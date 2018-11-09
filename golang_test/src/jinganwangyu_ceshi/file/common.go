package filehandle

import (
	"errors"
	"math/big"
	"math/rand"
	"net"
	"strconv"
	"sync"
	"time"
)

/*
	创建一个小于max的随机数
*/
var RandSeed int64 = 0

func createRandNum(max int) int {
	rand.Seed(RandSeed + time.Now().Unix())
	RandSeed++

	ret := rand.Intn(max)
	if ret != 0 {
		return ret
	}
	return createRandNum(max)
}

//创建一个随机MAC
func createRandMac() string {
	return strconv.Itoa(createRandNum(99)) + "-" +
		strconv.Itoa(createRandNum(99)) + "-" +
		strconv.Itoa(createRandNum(99)) + "-" +
		strconv.Itoa(createRandNum(99)) + "-" +
		strconv.Itoa(createRandNum(99)) + "-" +
		strconv.Itoa(createRandNum(99))
}

//创建一个随机URL
func createRandURL() string {
	return "http://www." + strconv.Itoa(createRandNum(99999)) + ".com"
}

func createRandIP() string {
	ip_str := strconv.Itoa(createRandNum(254)) + "." +
		strconv.Itoa(createRandNum(254)) + "." +
		strconv.Itoa(createRandNum(254)) + "." +
		strconv.Itoa(createRandNum(254))

	ret := big.NewInt(0)
	ret.SetBytes(net.ParseIP(ip_str).To4())

	return strconv.FormatInt(ret.Int64(), 10)
}

const (
	G_httpXml = "./WA_SOURCE_0001.xml"
	G_workDir = "./workdir"
	G_xmlName = "/GAB_ZIP_INDEX.xml"
)

type FilesHandler interface {
	Start()
	Stop() error
}

//event:
// - http
func NewHandler(event string, routine_num, record_num, period int) (FilesHandler, error) {
	switch event {
	case "http":
		h := &httpFileHandler{
			routineNum: routine_num,
			recordNum:  record_num,
			period:     period,
			wg:         &sync.WaitGroup{},
			quit:       make(chan struct{}),
		}

		return h, nil

	default:
		return nil, errors.New("Unsupported event type")
	}
}
