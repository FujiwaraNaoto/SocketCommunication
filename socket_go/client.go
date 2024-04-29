package main

import (
	"bufio"
	"fmt"
	"net"
	"time"
)

func main() {

	for {
		//TCPサーバに接続
		conn, err := net.Dial("tcp", "server:31400")
		if err != nil {
			fmt.Println(err)
			return
		}
		defer conn.Close()
		fmt.Fprintf(conn, "Connect to client\n")
		message, err := bufio.NewReader(conn).ReadString('\n')
		if err != nil {
			fmt.Println(err)
			return
		}

		fmt.Println("Message from server:", message)
		//1秒間お休みする
		time.Sleep(time.Second * 1)
	}
}
