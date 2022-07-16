//start code
var express = require('express');//This is how we create an express application

var app = require('express')();
//Calls the express function and puts new Express application inside the app variable (to start a new Express application)and app is an object with all functions that the express modul provides.


//To import the htp library so that i can use the http variable and use its code + create a server for http by method creatserver
var http = require('http').createServer(app);//to link server with client Because when the client contacts the server, the server will be able to send him the data

//The HTTP server will take as a parameter to use in sending and receiving between the client and the server
var io = require('socket.io')(http);//To manage messages between the client and the server.
 

//To specify the directory that contains the front-end files and which will be sent to the server
app.use(express.static(__dirname + '/web'));


var server_port = process.env.YOUR_PORT || process.env.PORT || 3000;
//Informs the browser the port number that the server uses in order for the browser to communicate with the server
http.listen(server_port, () => {
 console.log('listening on *:' + server_port);//print what port that server listen to
});
