package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"net"
	"time"
)

func main() {
	messages := []string{"CSS完全に理解した", "404 Not Found", "RaspberryPi", "Linux"}

	//現在時刻を取得，乱数に割り当てる
	rand.Seed(time.Now().UnixNano())

	for {
		//TCPサーバに接続
		conn, err := net.Dial("tcp", "server:31400") //dockerで動かす場合はこちら
		//conn, err := net.Dial("tcp", "localhost:31400") //手元で動かす場合はこちら
		if err != nil {
			fmt.Println(err)
			return
		}
		defer conn.Close()
		fmt.Fprintf(conn, "Connect to client\n")

		randomIndex := rand.Intn(len(messages))
		sendMessage := messages[randomIndex]
		_, err = conn.Write([]byte(sendMessage))

		if err != nil {
			fmt.Println("Error sending message:", err)
			return
		}

		recevedMessage, err := bufio.NewReader(conn).ReadString('\n')
		if err != nil {
			fmt.Println(err)
			return
		}

		fmt.Println("Message from server:", recevedMessage)
		//1秒間お休みする
		time.Sleep(time.Second * 1)
	}
}
