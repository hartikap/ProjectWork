$(document).ready(function() {

    $("#welcometext").text("Welcome "+ sessionStorage.username + "!");
    
    $("#button2").click(function() {
        
        var voltage = input.value*2.56;
        console.log(voltage);
        
        socket.emit('voltage update', voltage);
        
    });
    
    
    var socket = io();
    $('form').submit(function(){
    
        socket.emit('chat message', $('#m').val());
   
        $('#m').val('');
   
        return false;
 
    });
    
    
    
});