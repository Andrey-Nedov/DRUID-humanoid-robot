var mobile = false
var horizont = false

var first = true
var reload = true

var onDir = false
var onRot = false

var downVar = false
var angle = 0;

var dirClosed = true

var newDirClosed = true

var x = 0
var y = 0

function vibrate(val){
  if("vibrate" in navigator)  return navigator.vibrate(val);
  if("oVibrate" in navigator)  return navigator.oVibrate(val);
  if("mozVibrate" in navigator)  return navigator.mozVibrate(val);
  if("webkitVibrate" in navigator)  return navigator.webkitVibrate(val);
}




function sendGet(msg)
{
	try
	{
		var xhr = new XMLHttpRequest()
		xhr.open('GET', 'http://192.168.10.156/' + msg)
		xhr.send()
		if (xhr.status != 200) 
		{
			console.log( xhr.status + ': ' + xhr.statusText )
		} 
		else 
		{
			console.log( xhr.responseText )
		}
	}
	catch(e)
	{
		console.log(e)
	}
}

function init()
{
	if (/Android|webOS|iPhone|iPad|iPod|BlackBerry|BB|PlayBook|IEMobile|Windows Phone|Kindle|Silk|Opera Mini/i.test(navigator.userAgent)) 
	{
    	mobile = true

    	document.getElementById("direction").addEventListener("touchstart", dirMobDown)
    	document.getElementById("direction").addEventListener("touchend", dirMobUp)
    	document.getElementById("direction").addEventListener("touchmove", dirMobMove)

	}
	else
	{
		window.addEventListener("mousemove", function(e)
	 	{
	 		//console.log(e.clientX)
	 		x = e.clientX
	 		y = e.clientY
	 	})
		document.getElementById("rotation").addEventListener("mousemove", baraban)
		document.getElementById("direction").addEventListener("mousemove", dirMobMove)
	}

	setTimeout(                         //функция запускается асинхронно и проверяет не закончила ли рекурсия FindTrack поиск
        function run()
        {
        	var width = window.innerWidth
			|| document.documentElement.clientWidth
			|| document.body.clientWidth;

			var height = window.innerHeight
			|| document.documentElement.clientHeight
			|| document.body.clientHeight;

        	if(height > width)
			{
				if(!horizont)
				{
					document.getElementById('left').style.animation = " left_down_vert 300ms ease-in-out forwards"
					document.getElementById('right').style.animation = " right_down_vert 300ms ease-in-out forwards"
					document.getElementById('bottom').style.animation = " bottom_down_vert 300ms ease-in-out forwards"

					horizont = true
				}

				reload = true
				document.getElementById('rotation').style.width = "100vw";
				document.getElementById('rotation').style.height = "100vw";
				document.getElementById('rotation').style.marginTop = "10vw";
				document.getElementById('rotation').style.marginLeft = "0";

				document.getElementById('rl').style.width = "100vw"
				document.getElementById('rl').style.maxHeight = "35vw";
				document.getElementById('rl').style.maxHeight = "22.5vw";
				document.getElementById('rl').style.maxWidth = "100vw";

				document.getElementById('direction').style.width = "80vw";
				document.getElementById('direction').style.height = "80vw";
				document.getElementById('direction').style.marginTop = "20vw";
				document.getElementById('direction').style.marginLeft = "10vw";

				document.getElementById('centroid').style.width = "40vw";
				document.getElementById('centroid').style.height = "40vw";
				document.getElementById('centroid').style.marginTop = "20vw";
				document.getElementById('centroid').style.marginLeft = "20vw";

				document.getElementById('left').style.width = "14.8vw";
				document.getElementById('left').style.height = "19.8vw";
				document.getElementById('left').style.marginTop = "5.7vw";
				document.getElementById('left').style.marginLeft = "5.7vw";

				document.getElementById('right').style.width = "14.8vw";
				document.getElementById('right').style.height = "19.8vw";
				document.getElementById('right').style.marginTop = "5.7vw";
				document.getElementById('right').style.marginLeft = "19.8vw";

				document.getElementById('bottom').style.width = "24vw";
				document.getElementById('bottom').style.height = "8.3vw";
				document.getElementById('bottom').style.marginTop = "22.3vw";
				document.getElementById('bottom').style.marginLeft = "8vw";

				document.getElementById('solidFill').style.width = "28.8vw";
				document.getElementById('solidFill').style.height = "28.8vw";
				document.getElementById('solidFill').style.marginTop = "5.7vw";
				document.getElementById('solidFill').style.marginLeft = "5.6vw";

				document.getElementById('stop').style.width = "10vw";
				document.getElementById('stop').style.height = "10vw";
				document.getElementById('stop').style.marginTop = "116vw";
				document.getElementById('stop').style.marginLeft = "10vw";

				document.getElementById('speed').style.width = "18vw";
				document.getElementById('speed').style.height = "7vw";
				document.getElementById('speed').style.marginTop = "119vw";
				document.getElementById('speed').style.marginLeft = "70vw";

				document.getElementById('speedImg').style.width = "7vw";
				document.getElementById('speedImg').style.height = "7vw";
				document.getElementById('speedImg').style.marginTop = "0vw";
				document.getElementById('speedImg').style.marginLeft = "0vw";

				document.getElementById('speedText').style.fontSize = "5vw";
				document.getElementById('speedText').style.marginTop = "0.5vw";
				document.getElementById('speedText').style.marginLeft = "9vw";
			}
			else
			{
				if(horizont)
				{
					document.getElementById('left').style.animation = " left_down 3ms ease-in-out forwards"
					document.getElementById('right').style.animation = " right_down 3ms ease-in-out forwards"
					document.getElementById('bottom').style.animation = " bottom_down 3ms ease-in-out forwards"

					horizont = false
				}
				
				document.getElementById('rotation').style.width = "50vw";
				document.getElementById('rotation').style.height = "50vw";
				document.getElementById('rotation').style.marginLeft = "25vw";
				document.getElementById('rotation').style.marginTop = "-7vw";

				document.getElementById('rl').style.width = "25vw"
				document.getElementById('rl').style.maxHeight = "78px";
				document.getElementById('rl').style.maxWidth = "350px";

				document.getElementById('direction').style.width = "40vw";
				document.getElementById('direction').style.height = "40vw";
				document.getElementById('direction').style.marginLeft = "30vw";
				document.getElementById('direction').style.marginTop = "-2vw";

				document.getElementById('centroid').style.width = "20vw";
				document.getElementById('centroid').style.height = "20vw";
				document.getElementById('centroid').style.marginLeft = "10vw";
				document.getElementById('centroid').style.marginTop = "10vw";

				document.getElementById('left').style.width = "4.92vw";
				document.getElementById('left').style.height = "6.58vw";
				document.getElementById('left').style.marginLeft = "5.2vw";
				document.getElementById('left').style.marginTop = "5.3vw";

				document.getElementById('right').style.width = "4.92vw";
				document.getElementById('right').style.height = "6.58vw";
				document.getElementById('right').style.marginLeft = "10vw";
				document.getElementById('right').style.marginTop = "5.3vw";

				document.getElementById('bottom').style.width = "8vw";
				document.getElementById('bottom').style.height = "2.73vw";
				document.getElementById('bottom').style.marginLeft = "6vw";
				document.getElementById('bottom').style.marginTop = "11vw";

				document.getElementById('solidFill').style.width = "9.6vw";
				document.getElementById('solidFill').style.height = "9.6vw";
				document.getElementById('solidFill').style.marginLeft = "5.2vw";
				document.getElementById('solidFill').style.marginTop = "5.3vw";

				document.getElementById('stop').style.width = "4vw";
				document.getElementById('stop').style.height = "4vw";
				document.getElementById('stop').style.marginLeft = "11vw";
				document.getElementById('stop').style.marginTop = "33vw";

				document.getElementById('speed').style.width = "7vw";
				document.getElementById('speed').style.height = "3vw";
				document.getElementById('speed').style.marginLeft = "86vw";
				document.getElementById('speed').style.marginTop = "16vw";

				document.getElementById('speedImg').style.width = "1.8vw";
				document.getElementById('speedImg').style.height = "1.8vw";
				document.getElementById('speedImg').style.marginLeft = "0.8vw";
				document.getElementById('speedImg').style.marginTop = "0.8vw";

				document.getElementById('speedText').style.fontSize = "1.6vw";
				document.getElementById('speedText').style.marginLeft = "3.5vw";
				document.getElementById('speedText').style.marginTop = "0.8vw";
			}

            setTimeout(run, 100)
        }, 100)
}

function baraban(e)
{
	if(downVar)
	{
		var topRot = document.getElementById("rotation").getBoundingClientRect().top
 		var botRot = document.getElementById("rotation").getBoundingClientRect().bottom
 		var leftRot = document.getElementById("rotation").getBoundingClientRect().left
 		var rightRot = document.getElementById("rotation").getBoundingClientRect().right

 		var height = rightRot - leftRot
 		var width = botRot - topRot

 		var xRot
 		var yRot

 		if(mobile)
 		{
 			xRot = parseInt(e.changedTouches[0].pageX - leftRot)
 			yRot = parseInt(e.changedTouches[0].pageY - topRot)
 			// document.getElementById("rl").innerHTML = e.changedTouches[0].pageX + "<br>" + e.changedTouches[0].pageY
 		}
 		else
 		{
 			xRot = parseInt(e.clientX - leftRot)
 			yRot = parseInt(e.clientY - topRot)
 			// document.getElementById("rl").innerHTML = e.clientX + "<br>" + e.clientY
 		}

 		var quarter = 0

 		var newAngle = 0

 		var h = Math.abs(parseInt((height/2) - yRot))

 		var w = Math.abs(parseInt((width/2) - xRot))

 		var c = Math.sqrt(Math.pow(h, 2) + Math.pow(w, 2))

 		if(xRot - parseInt(height/2) > 0)	//правая половина
 		{
 			if(yRot - parseInt(width/2) < 0)	//первая четверть	
 			{
 				newAngle = (Math.asin(h/c)*180 / Math.PI)
 				//console.log(newAngle)
 			}

 			if(yRot - parseInt(width/2) > 0)	//четвертая четверть	
 			{
 				newAngle = 270 + 90 - (Math.asin(h/c)*180 / Math.PI)
 				//console.log(newAngle)
 			}
 		}

 		if(xRot - parseInt(height/2) < 0)	//левая половина
 		{
 			if(yRot - parseInt(width/2) < 0)	//вторая четверть	
 			{
 				newAngle = 90 + 90 - (Math.asin(h/c)*180 / Math.PI)
 				//console.log(newAngle)
 			}

 			if(yRot - parseInt(width/2) >= 0)	//третья четверть	
 			{
 				newAngle = (180 + (Math.asin(h/c)*180 / Math.PI))
 				//console.log(newAngle)
 			}
 		}

 		angle = 360 - parseInt(newAngle)

 		sendGet("a/" + parseInt(newAngle))

 		document.getElementById("rotation").style.transform = "rotate(" + angle + "deg)"
	}
}

function dirMobDown()	//mobile
{
	downVar = true
	downDir()
}

function dirMobUp()	//mobile
{
	downVar = true
	document.getElementById("rl").innerHTML = ""
	upDir()
}

function dirMobMove(e)
{
	var topDir = document.getElementById("direction").getBoundingClientRect().top
	var botDir = document.getElementById("direction").getBoundingClientRect().bottom
	var leftDir = document.getElementById("direction").getBoundingClientRect().left
	var rightDir = document.getElementById("direction").getBoundingClientRect().right

	var height = botDir - topDir
	var width = rightDir - leftDir

	if(mobile)
		{
			var xDir = parseInt(e.changedTouches[0].pageX - leftDir)
			var yDir = parseInt(e.changedTouches[0].pageY - topDir)

			if(!newDirClosed)
			{
				var quarter = 0

		 		var newAngle = 0

		 		var h = Math.abs(parseInt((height/2) - yDir))

		 		var w = Math.abs(parseInt((width/2) - xDir))

		 		var c = Math.sqrt(Math.pow(h, 2) + Math.pow(w, 2))

		 		if(xDir - parseInt(height/2) > 0)	//правая половина
		 		{
		 			if(yDir - parseInt(width/2) < 0)	//первая четверть	
		 			{
		 				newAngle = (Math.asin(h/c)*180 / Math.PI)
		 				//console.log(newAngle)
		 			}

		 			if(yDir - parseInt(width/2) > 0)	//четвертая четверть	
		 			{
		 				newAngle = 270 + 90 - (Math.asin(h/c)*180 / Math.PI)
		 				//console.log(newAngle)
		 			}
		 		}

		 		if(xDir - parseInt(height/2) < 0)	//левая половина
		 		{
		 			if(yDir - parseInt(width/2) < 0)	//вторая четверть	
		 			{
		 				newAngle = 90 + 90 - (Math.asin(h/c)*180 / Math.PI)
		 				//console.log(newAngle)
		 			}

		 			if(yDir - parseInt(width/2) >= 0)	//третья четверть	
		 			{
		 				newAngle = (180 + (Math.asin(h/c)*180 / Math.PI))
		 				//console.log(newAngle)
		 			}
		 		}

		 		var angleDir = parseInt(newAngle)

		 		var power = parseInt((c*200)/(height*0.8))

		 		if(power > 100)
		 			power = 100

		 		// vibrate(power*0.1)

		 		sendGet("d/" + angleDir + "/" + power)
			}
		}
		else
		{
			var xDir = parseInt(e.clientX - leftDir)
			var yDir = parseInt(e.clientY - topDir)

			if(!newDirClosed)
			{
				var quarter = 0

		 		var newAngle = 0

		 		var h = Math.abs(parseInt((height/2) - yDir))

		 		var w = Math.abs(parseInt((width/2) - xDir))

		 		var c = Math.sqrt(Math.pow(h, 2) + Math.pow(w, 2))

		 		if(xDir - parseInt(height/2) > 0)	//правая половина
		 		{
		 			if(yDir - parseInt(width/2) < 0)	//первая четверть	
		 			{
		 				newAngle = (Math.asin(h/c)*180 / Math.PI)
		 				//console.log(newAngle)
		 			}

		 			if(yDir - parseInt(width/2) > 0)	//четвертая четверть	
		 			{
		 				newAngle = 270 + 90 - (Math.asin(h/c)*180 / Math.PI)
		 				//console.log(newAngle)
		 			}
		 		}

		 		if(xDir - parseInt(height/2) < 0)	//левая половина
		 		{
		 			if(yDir - parseInt(width/2) < 0)	//вторая четверть	
		 			{
		 				newAngle = 90 + 90 - (Math.asin(h/c)*180 / Math.PI)
		 				//console.log(newAngle)
		 			}

		 			if(yDir - parseInt(width/2) >= 0)	//третья четверть	
		 			{
		 				newAngle = (180 + (Math.asin(h/c)*180 / Math.PI))
		 				//console.log(newAngle)
		 			}
		 		}

		 		var angleDir = parseInt(newAngle)

		 		var power = parseInt((c*200)/(height*0.8))

		 		if(power > 100)
		 			power = 100

		 		var val = 5*power

		 		if("vibrate" in navigator) navigator.vibrate(val);
				if("oVibrate" in navigator)  navigator.oVibrate(val);
				if("mozVibrate" in navigator) navigator.mozVibrate(val);
				if("webkitVibrate" in navigator) navigator.webkitVibrate(val);
				// alert("!")

		 		sendGet("d/" + angleDir + "/" + power)
			}
		}
}

function down()		//desktop
{
	if(!mobile)
	{
		downVar = true

		if(dirClosed)
			if(onDir)
			{
				downDir()	
				dirClosed = false
			}
	}
}

function up()		//desktop
{
	if(!mobile)
	{
		downVar = false

		if(!dirClosed)
			if(onDir)
			{
				upDir()
				dirClosed = true
			}
	}
}

function enterDir()
{
	onDir = true
	onRot = false
}

function leaveDir()
{
	onDir = false
	if(!dirClosed)
	{
		upDir()
		dirClosed = true
	}
}

function enterRot()
{
	onDir = false
	onRot = true
}

function leaveRot()
{
	onRot = false
}

function downDir()			// если мышка на direction опутилась
{
	newDirClosed = false

	sendGet("dirDown")
	///document.getElementById('solidFill').style.display = "none"
	document.getElementById('solidFill').style.animation = " sol_down 200ms ease-in-out forwards"

	setTimeout(function()
		{
			document.getElementById('left').style.display = "block"
			document.getElementById('right').style.display = "block"
			document.getElementById('bottom').style.display = "block"

			if(!horizont)
			{
				document.getElementById('left').style.animation = " left_up 300ms ease-in-out forwards"
				document.getElementById('right').style.animation = " right_up 300ms ease-in-out forwards"
				document.getElementById('bottom').style.animation = " bottom_up 300ms ease-in-out forwards"
			}
			else
			{
				document.getElementById('left').style.animation = " left_up_vert 300ms ease-in-out forwards"
				document.getElementById('right').style.animation = " right_up_vert 300ms ease-in-out forwards"
				document.getElementById('bottom').style.animation = " bottom_up_vert 300ms ease-in-out forwards"
			}
		}, 200)

	if(first)
	{
		sendGet("start")
		// setTimeout(function()
		// {
			document.getElementById('rotation').style.animation = ""
			document.getElementById('rotation').style.display = "block"
			document.getElementById('rotation').style.animation = "  rotat_up 800ms ease-in-out forwards"
		// }, 300)

		setTimeout(function()
		{
			document.getElementById('speed').style.animation = " speed_up 300ms ease-in-out forwards"
			document.getElementById('body').removeChild(document.getElementById('rotation'))

			var newRot = document.createElement("div")
		    newRot.className = "rotation"
		    newRot.id = "rotation"
		    newRot.addEventListener("mouseenter", function(){enterRot()}, false)             //ставим на event функцию и параметром номера трека
    		newRot.addEventListener("mouseleave", function(){leaveRot()}, false)             //ставим на event функцию и параметром номера трека
    		newRot.addEventListener("mousemove", baraban)
    		newRot.style.display = "block"

		    document.getElementById("body").insertBefore(newRot, document.getElementById("direction"))                                           //добавьте элемент в DOM и вы прекрасны!

		    if(mobile)
		    {
		    	document.getElementById("rotation").addEventListener("touchmove", baraban)
		    }
		}, 1000)

		setTimeout(function()
		{
			document.getElementById('stop').style.animation = ""
			document.getElementById('stop').style.display = "block"
			document.getElementById('stop').style.animation = " stop_up 300ms ease-in-out forwards"
		}, 600)

		first = false
	}
}

function upDir()		// если мышка на direction поднялась
{
	newDirClosed = true

	sendGet("dirUp")

	if(!first)
	{
		setTimeout(function()
		{
			if(!horizont)
			{
				document.getElementById('left').style.animation = " left_down 300ms ease-in-out forwards"
				document.getElementById('right').style.animation = " right_down 300ms ease-in-out forwards"
				document.getElementById('bottom').style.animation = " bottom_down 300ms ease-in-out forwards"
			}
			else
			{
				document.getElementById('left').style.animation = " left_down_vert 300ms ease-in-out forwards"
				document.getElementById('right').style.animation = " right_down_vert 300ms ease-in-out forwards"
				document.getElementById('bottom').style.animation = " bottom_down_vert 300ms ease-in-out forwards"
			}
		}, 500)

		setTimeout(function()
		{
			document.getElementById('solidFill').style.animation = ""
			document.getElementById('solidFill').style.display = "block"
			document.getElementById('solidFill').style.animation = " sol_up 200ms ease-in-out forwards"
		}, 800)
	}
}


function stop()
{
	sendGet("stop")

	document.getElementById('solidFill').style.display = "none"

	if(!horizont)
	{
		document.getElementById('left').style.animation = " left_up 300ms ease-in-out forwards"
		document.getElementById('right').style.animation = " right_up 300ms ease-in-out forwards"
		document.getElementById('bottom').style.animation = " bottom_up 300ms ease-in-out forwards"
	}
	else
	{
		document.getElementById('left').style.animation = " left_up_vert 300ms ease-in-out forwards"
		document.getElementById('right').style.animation = " right_up_vert 300ms ease-in-out forwards"
		document.getElementById('bottom').style.animation = " bottom_up_vert 300ms ease-in-out forwards"
	}

	setTimeout(function()
		{
			document.getElementById('rotation').style.animation = "  rotat_down 500ms ease-in-out forwards"
		}, 200)

	setTimeout(function()
		{
			document.getElementById('speed').style.animation = " speed_down 300ms ease-in-out forwards"
		}, 500)

	setTimeout(function()
		{
			document.getElementById('stop').style.animation = " stop_down 300ms ease-in-out forwards"
		}, 600)

	setTimeout(function()
		{
			document.getElementById('stop').style.display = "none"
		}, 900)

	
	setTimeout(function()
		{
			if(!horizont)
			{
				document.getElementById('left').style.animation = " left_down 300ms ease-in-out forwards"
				document.getElementById('right').style.animation = " right_down 300ms ease-in-out forwards"
				document.getElementById('bottom').style.animation = " bottom_down 300ms ease-in-out forwards"
			}
			else
			{
				document.getElementById('left').style.animation = " left_down_vert 300ms ease-in-out forwards"
				document.getElementById('right').style.animation = " right_down_vert 300ms ease-in-out forwards"
				document.getElementById('bottom').style.animation = " bottom_down_vert 300ms ease-in-out forwards"	
			}

			setTimeout(function()
			{
				document.getElementById('solidFill').style.animation = ""
				document.getElementById('solidFill').style.display = "block"
				document.getElementById('solidFill').style.animation = " sol_up 1300ms ease-in-out forwards"
			}, 800)

			setTimeout(function()
			{
				// document.getElementById('left').style.display = "none"
				// document.getElementById('right').style.display = "none"
				// document.getElementById('bottom').style.display = "none"
				document.getElementById('solidFill').style.animation = "waitTap 3s infinite  ease-in-out"
			}, 2100)

		}, 900)

	first = true
}