build:
	gcc -o ./out/server ./src/main.c 
server:
	gcc -o ./out/hello_server ./src/server.c 
client:
	gcc -o ./out/hello_client ./src/client.c 
clean:
	rm -f main 
