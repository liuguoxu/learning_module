package main

import (
	"fmt"
	"log"
	"os"
)

/*
func New(out io.writer, prefix string, flag int) *Logger
该函数一共有三个参数：
（1）输出位置out，是一个io.Writer对象，该对象可以是一个文件也可以是实现了该接口的对象。通常我们可以用这个来指定日志输出到哪个文件。
（2）prefix 我们在前面已经看到，就是在日志内容前面的东西。我们可以将其置为 "[Info]" 、 "[Warning]"等来帮助区分日志级别。
（3） flags 是一个选项，显示日志开头的东西，可选的值有：
Ldate         = 1 << iota     // 形如 2009/01/23 的日期
Ltime                         // 形如 01:23:23   的时间
Lmicroseconds                 // 形如 01:23:23.123123   的时间
Llongfile                     // 全路径文件名和行号: /a/b/c/d.go:23
Lshortfile                    // 文件名和行号: d.go:23
LstdFlags     = Ldate | Ltime // 日期和时间
*/

var LOG_DBG, LOG_TRAC, LOG_INFO, LOG_WARN, LOG_ERRO, LOG_FATAL *log.Logger

const (
	FATAL_LEVEL = iota + 1
	ERRO_LEVEL
	WARN_LEVEL
	INFO_LEVEL
	TRAC_LEVEL
	DBG_LEVEL
)

var lvl int = WARN_LEVEL

/*
	初始化日志
*/
func LogInit() {
	fmt.Println("PKG:ik_log init!")

	null_file, err := os.OpenFile("/dev/null", os.O_RDWR, os.ModePerm)

	if err != nil {
		panic(err)
	}

	outfile := os.Stdout

	_new_log_func := func(level int, prefix string, logger **log.Logger) {
		if lvl >= level {
			*logger = log.New(outfile, prefix, log.LstdFlags|log.Lshortfile)
		} else {
			*logger = log.New(null_file, prefix, log.LstdFlags|log.Lshortfile)
		}
	}

	_new_log_func(DBG_LEVEL, "[DBG]", &LOG_DBG)
	_new_log_func(TRAC_LEVEL, "[TRAC]", &LOG_TRAC)
	_new_log_func(INFO_LEVEL, "[INFO]", &LOG_INFO)
	_new_log_func(WARN_LEVEL, "[WARNING]", &LOG_WARN)
	_new_log_func(ERRO_LEVEL, "[ERROR]", &LOG_ERRO)
	_new_log_func(FATAL_LEVEL, "[FATAL]", &LOG_FATAL)

}

/*
	重置日志等级
*/

func ResetLogLevel(lvl int) {
	var (
		err     error
		outfile = os.Stdout
	)

	null_file, err := os.OpenFile("/dev/null", os.O_RDWR, os.ModePerm)
	if err != nil {
		panic(err)
	}

	_set_level_func := func(logger_lvl int, logger *log.Logger) {
		if lvl >= logger_lvl {
			logger.SetOutput(outfile)
		} else {
			logger.SetOutput(null_file)
		}
	}

	_set_level_func(DBG_LEVEL, LOG_DBG)
	_set_level_func(TRAC_LEVEL, LOG_TRAC)
	_set_level_func(INFO_LEVEL, LOG_INFO)
	_set_level_func(WARN_LEVEL, LOG_WARN)
	_set_level_func(ERRO_LEVEL, LOG_ERRO)
	_set_level_func(FATAL_LEVEL, LOG_FATAL)

}

func main() {

	LogInit()

	fmt.Println("level is :", lvl)
	LOG_DBG.Println("a")
	LOG_TRAC.Println("a")
	LOG_INFO.Println("a")
	LOG_WARN.Println("a")
	LOG_ERRO.Println("a")
	LOG_FATAL.Println("a")

	fmt.Println("level is", TRAC_LEVEL)

	ResetLogLevel(TRAC_LEVEL)
	LOG_DBG.Println("a")
	LOG_TRAC.Println("a")
	LOG_INFO.Println("a")
	LOG_WARN.Println("a")
	LOG_ERRO.Println("a")
	LOG_FATAL.Println("a")

}
