package filehandle

import (
	"fmt"
	"os"
	"os/exec"
)

//1. compress .bcp and .xml files
//2. encrypt zip
//3. send by ftp
func zipAndFtp(path, zip_name string) {
	full_name := path + "/" + zip_name
	zip_cmd := fmt.Sprintf("zip -0 -j -m %s %s/*.xml %s/*.bcp", full_name, path, path)
	cmd := exec.Command("/bin/bash", "-c", zip_cmd)
	_, err := cmd.Output()
	if err != nil {
		fmt.Println("zip error:", err)
		return
	}
	fmt.Println("zip successfully~")

	encrypt_zip(full_name)

	//send by ftp
	ftp_account := "ikuai"
	ftp_psd := "euJmc]pp3nbvj7xsoMfr"
	ftp_host := "58.87.74.75"
	ftp_port := "51819"

	cmd_string := fmt.Sprintf("curl --ftp-create-dirs --connect-timeout 10 "+
		"-m 20 -u %s:%s -T %s ftp://%s:%s/%s "+
		"-Q \"-RNFR %s\" -Q \"-RNTO %s\"",
		ftp_account, ftp_psd, full_name, ftp_host, ftp_port, zip_name+".tmp", zip_name+".tmp", zip_name)

	//fmt.Println(cmd_string)

	cmd = exec.Command("/bin/bash", "-c", cmd_string)
	if _, err := cmd.Output(); err != nil {
		fmt.Println("ftp error:", err)
		return
	}
	fmt.Println("ftp send", zip_name, "successfully~")

	/*上传无论成功失败都把zip删掉*/
	os.Remove(full_name)
}

/*
encode
*/
func encrypt_zip(name string) {
	key_str := "7062776a24234021"
	iv_str := "73616c7423264021"

	tmp_en := fmt.Sprintf("%s.en", name)
	en_cmd := fmt.Sprintf("openssl des-cbc -K %s -iv %s -nosalt -in %s -out %s", key_str, iv_str, name, tmp_en)
	//fmt.Println("en_cmd:", en_cmd)
	cmd := exec.Command("/bin/bash", "-c", en_cmd)
	if _, err := cmd.Output(); err != nil {
		fmt.Println("des-cbc error:", err)
		return
	}
	fmt.Println("des-cbc successfully~")

	os.Remove(name)

	base64_cmd := fmt.Sprintf("openssl base64 -in %s -out %s", tmp_en, name)
	//fmt.Println("base64_cmd:", base64_cmd)

	cmd = exec.Command("/bin/bash", "-c", base64_cmd)
	if _, err := cmd.Output(); err != nil {
		fmt.Println("base64 error:", err)
		return
	}

	fmt.Println("base64 successfully~")

	os.Remove(tmp_en)
}
