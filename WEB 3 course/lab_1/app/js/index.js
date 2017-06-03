"use strict";

var content;
function poshlopoehalo(){
  return new Promise((resolve, reject) => {
     var timerId = setInterval( function() {
      $.ajax({
        url: 'https://randomuser.me/api/',
        dataType: 'json',
        success: function(data) {
          content = JSON.stringify(data);
          console.log(content);
          var template = Handlebars.compile( $('#template').html() );
          $('.results').append(template(data));
        }
      });
    },10000);
  })
  .catch(error => {
    alert(error); // Error: Not Found
  });
};

poshlopoehalo();
