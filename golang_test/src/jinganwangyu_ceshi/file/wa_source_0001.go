package filehandle

import (
	"fmt"
	"os"
	"strconv"
	"sync"
	"time"
)

//WA_SOURCE_0001
type httpFileHandler struct {
	//go routine num
	routineNum int

	//record num in bcp
	recordNum int

	//send zip period, seconds
	period int

	wg   *sync.WaitGroup
	quit chan struct{}

	FilesHandler
}

func (h *httpFileHandler) Start() {
	h.wg.Add(1)
	defer h.wg.Done()

	msg, err := Parse_xml(G_httpXml)
	if err != nil {
		panic(err)
	}

	os.Mkdir(G_workDir, 0777)

	one_row1 := "			3	069567814009043000620	1020002	1928889305		"

	//ip	port
	one_row2 := "		80			AA-BB-CC-DD-EE-FF	"
	//time
	one_row3 := "	145	全讯汇聚网络科技（北京）有限公司	34120121012428aabbccddeeff1541388478	1020002	AA-BB-CC-DD-EE-FF						990	AA-BB-CC-DD-EE-FF	34120121012428	116.29826	39.82296		069567814009043000620					3232235836	410526					410526	0			069567814			410526		410526	410526										01	34120121012428aabbccddeeff1541388478	1000000	"
	//http://www.163.com/		//url
	one_row4 := "														"

	table := "	"

	for r := 0; r < h.routineNum; r++ {
		r_NO := r
		go func() {
			h.wg.Add(1)
			defer h.wg.Done()
			fmt.Println("http goroutine", r_NO, "start!")

			index := createRandNum(99999)
			work_path := G_workDir + "/http_" + strconv.Itoa(r_NO)
			os.Mkdir(work_path, 0777)
			timer := time.NewTicker(2)
			for {
				select {
				case <-h.quit:
					fmt.Println("http goroutine", r_NO, "stop!")
					return

				case <-timer.C:
					if index > 99999 {
						index = 0
					}
					xml_data := msg
					now := strconv.FormatInt(time.Now().Unix(), 10)
					serial_no := fmt.Sprintf("%05d", index)
					bcp_name := "/145-410526-" + now + "-" + serial_no + "-WA_SOURCE_0001-0.bcp"
					bcp_whole_name := work_path + bcp_name
					f, err := os.OpenFile(bcp_whole_name, os.O_RDWR|os.O_CREATE|os.O_APPEND, 0666)
					if err != nil {
						panic(err)
					}

					for row := 0; row < h.recordNum; row++ {
						port := strconv.Itoa(createRandNum(65535))

						row_data := one_row1 + createRandIP() + table + table + port + one_row2 + now + one_row3 + createRandURL() + one_row4
						f.WriteString(row_data + "\n")
					}
					f.Close()
					xml_data.Dataset1.Data1.Dataset2.Data2.Dataset3[0].Data3[0].Items[1].Val = bcp_name
					xml_data.Dataset1.Data1.Dataset2.Data2.Dataset3[0].Data3[0].Items[2].Val = strconv.Itoa(h.recordNum)
					Create_xml(work_path+G_xmlName, xml_data)
					zip_name := "145-069567814-410526-341201-" + now + "-" + fmt.Sprintf("%05d", index) + ".zip"
					zipAndFtp(work_path, zip_name)

				}
			}
		}()
	}

}

func (h *httpFileHandler) Stop() error {
	close(h.quit)
	h.wg.Wait()
	return nil
}
