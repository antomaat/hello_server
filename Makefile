build:
	gcc -o ./out/main ./src/main.c 
server:
	gcc -o ./out/server ./src/server.c 
client:
	gcc -o ./out/client ./src/client.c 
clean:
	rm -f main 
