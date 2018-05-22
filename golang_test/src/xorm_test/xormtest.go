//测试xorm使用

package main

import (
	"fmt"
	"time"

	_ "github.com/go-sql-driver/mysql"
	"github.com/go-xorm/core"
	"github.com/go-xorm/xorm"
)

const (
	DB_user     = "root"
	DB_password = "660108"
	DB_ip       = "first_mysql"
	DB_port     = 3306
	DB_name     = "test_user"
)

type User struct {
	Id       int       `xorm:"not null pk autoincr INT(11)"`
	Username string    `xorm:"not null VARCHAR(32)"`
	Birthday time.Time `xorm:"DATE"`
	Sex      string    `xorm:"CHAR(1)"`
	Address  string    `xorm:"VARCHAR(256)"`
}

func main() {
	dataSourceName := fmt.Sprintf("%s:%s@(%s:%d)/%s?charset=utf8", DB_user, DB_password, DB_ip, DB_port, DB_name)
	//新建引擎
	x_engine, err := xorm.NewEngine("mysql", dataSourceName)
	defer x_engine.Close()
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println("new engine success")
	//ping 测试
	if err = x_engine.Ping(); err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println("ping success")
	//开启日志
	x_engine.ShowSQL(true)

	//设置连接池大小
	x_engine.SetMaxIdleConns(5)
	//设置最大连接数
	x_engine.SetMaxOpenConns(6)

	//名称映射规则主要负责结构体名称到表名和结构体field到表字段的名称映射
	x_engine.SetTableMapper(core.SnakeMapper{})

	new_user := &User{
		Username: "jack",
		Sex:      "Y",
		Address:  "USA",
	}

	affected, err := x_engine.Insert(new_user)
	fmt.Println(affected)
}
