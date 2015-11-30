var express = require('express');
var app = express();
var path = require("path");
var used_port = 8081;

/*/ This responds with "Hello World" on the homepage
app.get('/', function (req, res) {
   console.log("Got a GET request for the homepage");
   res.send('Hello GET');
})*/

//MIDDLEWARES------------------------------------------

// This responds a POST request for the homepage
app.post('/', function (req, res) {
   console.log("Got a POST request for the homepage");
   res.send('Hello POST');
})

// This responds a DELETE request for the /del_user page.
app.delete('/del_user', function (req, res) {
   console.log("Got a DELETE request for /del_user");
   res.send('Hello DELETE');
})

/*/ This responds to a GET request for the /process_get uri
app.get('/process_get', function (req,res) { 
    // Prepare output in JSON format
   response = {
       first_name:req.query.user_name
   };
  
    console.log(response);
    //express.static('Views/Control.html')
   // res.redirect('Views/Control.html');
   res.end(JSON.stringify(response));
    
})*/


app.use('/',express.static(path.join(__dirname, 'Views')));
app.use('/css',express.static(path.join(__dirname, 'css')));
app.use('/controllers',express.static(path.join(__dirname, 'controllers')));
app.use('/lib',express.static(path.join(__dirname, 'lib')));


// ROUTERS---------------------------------------------

var server = app.listen(used_port, function () {

  var host = server.address().address
  var port = server.address().port
  console.log("Example app listening at http://%s:%s", host, port)

})