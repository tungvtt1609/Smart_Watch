const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
  <meta charset="UTF-8">
  <title>Monitoring Heart Rate (HeartBeat)</title>
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.1/dist/css/bootstrap.min.css"
  integrity="sha384-zCbKRCUGaJDkqS1kPbPd7TveP5iyJE0EjAuZQTgFLD2ylzuqKfdKlfG/eSrtxUkn" crossorigin="anonymous">
<script type="text/javascript" src="https://gc.kis.v2.scr.kaspersky-labs.com/FD126C42-EBFA-4E12-B309-BB3FDD723AC1/main.js?attr=o5L-bkFGq148lx49w3l9xBxQHSrAwYlhOJ2zeyyY2x0HKfP0EH9fkMUfKf_iylGOzmKa0CZEkRqaZNamm0KcaQ6nKVQ576dFcY6tE1ypB1vyValW4y0kqqK9KjFKQ4Vuo_QQk8XnXrf3ru4WtyFRue9Rnual-vUgzM_5APh5_LH59A1WdMocpkXCPoytW55-DLCYvAIx7FvGe5FmNm7lJSEpI6rcXsSggV6XOAHoynnJrh-afMOParier6hDY6zzaNRuwv7fnoyqduA0ahV4Ds18iFHxpZi4pSXaJ7SqOM8PY9RmXpMiEcDs9CY-xcBP6v0ZCc5y9KeXjCAplN-iINdv1eYamrOO6QZkvbZv4UpYcKYc1ZwU6FILaL2W4FpW" charset="UTF-8"></script></head>

<body>

  
  <div class="container">
      <div class="row item-wrap">
        <h1 style="color:#7d0633;font-family:consolas;">Monitoring Heart Rate and Blood Pressure</h1>
      
      </div>
      <div class="row item-wrap">
    
        <img src=" data:image/png;base64,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" />
      </div>
    <div class="row">
      <div class="col-12 col-lg-4 item-wrap">
        <div class="flex-item">
          <canvas id="myCanvas" width="330" height="200"></canvas>
          <p>Min = 0 &nbsp;&nbsp;&nbsp; Max = 220</p>
        </div>
      </div>
      <div class="col-12 col-lg-4 item-wrap">
        <div class="flex-item">
          <canvas id="myCanvas1" width="330" height="200"></canvas>
          <p>Min = 0 &nbsp;&nbsp;&nbsp; Max = 220</p>
        </div>
      </div>
      <div class="col-12 col-lg-4 item-wrap">
        <div class="flex-item">
          <canvas id="myCanvas2" width="330" height="200"></canvas>
          <p>Min = 0 &nbsp;&nbsp;&nbsp; Max = 220</p>
        </div>
      </div>
    </div>
    </div>
    <br>
    <br>

  <!-- <div class="flex-container">
    <div class="flex-item">
      <canvas id="myCanvas" width="500" height="200"></canvas>
      <p>Min = 0 &nbsp;&nbsp;&nbsp; Max = 220</p>
      <p>Please wait 10 seconds to get the Value</p>
    </div>

    <div class="flex-item">
      <canvas id="myCanvas1" width="500" height="200"></canvas>
      <p>Min = 0 &nbsp;&nbsp;&nbsp; Max = 220</p>
      <p>Please wait 10 seconds to get the Value</p>
    </div>

    <div class="flex-item">
      <canvas id="myCanvas2" width="500" height="200"></canvas>
      <p>Min = 0 &nbsp;&nbsp;&nbsp; Max = 220</p>
      <p>Please wait 10 seconds to get the Value</p>
  </div> -->

  <style>
    html {
      font-family: Arial;
      display: inline-block;
      margin: 0px auto;
      text-align: center;
    }
  
    h1 {
      font-size: 1.5rem;
    }
  
    .flex-container {
      display: flex;
      flex-direction: row;
      background-color: 0x7d0633;
      align-items: center;
      justify-content: center;
    }
  
    .item-wrap {
      justify-content: center;
      text-align: center;
    }
    .flex-item {
      /* display: inline-block; */
      background-color: white;
      padding: 20px;
      font-size: 20px;
      align-items: center;
      justify-content: center;
    }

  </style>

  <script>
    var myVar = setInterval(myTimer, 1000); //--> Create a loop to send a request to NodeMCU to get the BPM value every 1 second.
    var getHR = 0; //--> Variable to get the BPM value from NodeMCU.
    var getSYS = 0; //--> Variable to get the SYS value from NodeMCU.
    var getDIA = 0; //--> Variable to get the DIA value from NodeMCU.

    function myTimer() {
      getHeartRateVal();
      getSYSPressureVal();
      getDIAPressureVal();
    }

    //------------------------------------------------------------Function for sending request to NodeMCU to get BPM value.
    function getHeartRateVal() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          getHR = this.responseText;
        }
      };
      xhttp.open("GET", "getHeartRate", true);
      xhttp.send();
    }
    //------------------------------------------------------------


    //------------------------------------------------------------Function for sending request to NodeMCU to get SYS value.
    function getSYSPressureVal(){
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange =function(){
        if(this.readyState == 4 && this.status == 200){
          getSYS = this.responseText;
          
        }
      };
      xhttp.open("GET", "getSYSPressure", true);
      xhttp.send();
    }
    //------------------------------------------------------------


    //------------------------------------------------------------Function for sending request to NodeMCU to get DIA value.
    function getDIAPressureVal() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function(){
        if(this.readyState == 4 && this.status == 200){
          getDIA = this.responseText;
        }
      };
      xhttp.open("GET", "getDIAPressure", true);
      xhttp.send();
    }
    //-------------------------------------------------------------


    //------------------------------------------------------------Display the BPM value and create a circle progress bar.
    var canvas = document.getElementById('myCanvas');
    var context = canvas.getContext('2d');
    var start = 1.58;
    var cw = context.canvas.width / 2;
    var ch = context.canvas.height / 2;
    var diff;

    var cnt = 0;
    var bar = setInterval(progressBar, 10);
    function progressBar() {
      var HR = map(getHR, 0, 220, 0, 100);
      diff = (cnt / 100) * Math.PI * 2;
      context.clearRect(-100, 0, 400, 200);
      context.beginPath();
      context.arc(cw, ch, 70, 0, 2 * Math.PI, false);
      context.fillStyle = '#FFF';
      context.fill();
      context.strokeStyle = '#e7f2ba';
      if(getHR <=49 || getHR >= 130){
        context.strokeStyle = '#fa8072';
      }
      context.stroke();
      context.fillStyle = '#000';
      context.strokeStyle = '#b3cf3c';
      context.textAlign = 'center';
      if(getHR <= 49 || getHR >= 130){
        context.strokeStyle = '#ff0000';
        context.textAlign = 'center';
      }
      context.lineWidth = 15;
      context.font = '15pt Verdana';
      context.beginPath();
      context.arc(cw, ch, 70, start, diff + start, false);
      context.stroke();
      context.fillText(getHR + ' BPM', cw + 2, ch + 6);

      if (cnt < HR) {
        cnt++;
      }

      if (cnt > HR) {
        cnt--;
      }
    }
    //------------------------------------------------------------

    //------------------------------------------------------------Display the SYS value and create a circle progress bar.
    var canvas1 = document.getElementById('myCanvas1');
    var context1 = canvas1.getContext('2d');
    var start1 = 1.58;
    var cw1 = context1.canvas.width / 2;
    var ch1 = context1.canvas.height / 2;
    var diff1;

    var cnt1 = 0;
    var bar1 = setInterval(progressBar1, 10);
    function progressBar1() {
      var SYS = map(getSYS  , 0, 220, 0, 100);
      diff1 = (cnt1 / 100) * Math.PI * 2;
      context1.clearRect(0, 0, 400, 200);
      context1.beginPath();
      context1.arc(cw, ch, 70, 0, 2 * Math.PI, false);
      context1.fillStyle = '#FFF';
      context1.fill();
      context1.strokeStyle = '#e7f2ba';
      if(getSYS <=49 || getSYS >= 180){
        context.strokeStyle = '#fa8072';
      }
      context1.stroke();
      context1.fillStyle = '#000';
      context1.strokeStyle = '#b3cf3c';
      context1.textAlign = 'center';
      if(getSYS <= 49 || getSYS >= 180){
        context.strokeStyle = '#ff0000';
        context.textAlign = 'center';
      }
      context1.lineWidth = 15;
      context1.font = '15pt Verdana';
      context1.beginPath();
      context1.arc(cw1, ch1, 70, start1, diff1 + start1, false);
      context1.stroke();
      context1.fillText(getSYS + ' mmHG', cw1 + 2, ch1 + 6);

      if (cnt1 < SYS) {
        cnt1++;
      }

      if (cnt1 > SYS) {
        cnt1--;
      }
    }
    //------------------------------------------------------------

    //------------------------------------------------------------Display the DIA value and create a circle progress bar.
    var canvas2 = document.getElementById('myCanvas2');
    var context2 = canvas2.getContext('2d');
    var start2 = 1.58;
    var cw2 = context2.canvas.width/2;
    var ch2 = context2.canvas.height/2;
    var diff2;

    var cnt2 = 0;
    var bar2 = setInterval(progressBar2, 10);
    function progressBar2() {
      var DIA = map(getDIA, 0, 220, 0, 100);
      diff2 = (cnt2/100)*Math.PI*2;
      context2.clearRect(0, 0, 400, 200);
      context2.beginPath();
      context2.arc(cw, ch, 70, 0, 2*Math.PI, false);
      context2.fillStyle = '#FFF';
      context2.fill();
      context2.strokeStyle = '#e7f2ba';
      if(getDIA <=49 || getDIA >= 180){
        context.strokeStyle = '#fa8072';
      }
      context2.stroke();
      context2.fillStyle = '#000';
      context2.strokeStyle = '#b3cf3c';
      context2.textAlign = 'center';
      if(getDIA <= 49 || getDIA >= 160){
        context.strokeStyle = '#ff0000';
        context.textAlign = 'center';
      }
      context2.lineWidth = 15;
      context2.font = '15pt Verdana';
      context2.beginPath();
      context2.arc(cw2, ch2, 70, start2, diff2 + start2, false);
      context2.stroke();
      context2.fillText(getDIA + ' mmHG', cw2 + 2, ch2 + 6);

      if (cnt2 < DIA) {
        cnt2++;
      }

      if (cnt2 > DIA) {
        cnt2--;
      }
    }
    //------------------------------------------------------------

    //------------------------------------------------------------Scale from the BPM value to the Progress bar value.
    // The BPM value is min = 0 and max = 220 is scaled to the Progress bar value min = 0 and max = 100.
    function map(x, in_min, in_max, out_min, out_max) {
      return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }
    //------------------------------------------------------------
  </script>
</body>
</html>
)=====";
