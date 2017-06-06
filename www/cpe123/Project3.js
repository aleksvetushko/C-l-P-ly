function setup() {
  createCanvas(400, 400);
  background(117, 100, 77);

  noStroke();
  fill(90, 110, 110);
  beginShape();
  curveVertex(-400,197);
  curveVertex(0,37);
  curveVertex(400,37);
  curveVertex(800,197);
  endShape();

  rect(50, 30, 300, 350);
  for (var i = 0; i < 20000; i++) {
    drawTiles();
  }

  fill(117, 100, 77);
  rect(0,0,50,400);
  rect(350,0,50,400);
  beginShape();
  curveVertex(-400,560);
  curveVertex(0,400);
  curveVertex(400,400);
  curveVertex(800,560);
  endShape();

  stroke(117, 100, 77);
  strokeWeight(25);
  curve(100,600, 50,400, 370,0, 450,-100);

  stopHere = 0;
  stopThere = 0;

  // stroke(156, 226, 210);
  // noFill();
  // strokeWeight(10);
  // curve(-220,500, 200,350, 150,200, -200,200);
  // curve(-220,500, 200,351, 165,160, -200,100);
  // curve(-220,500, 200,349, 180,120, -200,50);
  // curve(-220,500, 200,352, 195,80, -250,25);

}

function drawTiles() {
  noStroke();
  fill(random(80, 10), random(100, 120), random(100, 120));
  x = random(50, 350);
  y = random(0.0005 * Math.pow(x-200,2) + 20, 400);
  ellipse(x, y, 5, 7);
}
function drawFlower(cx, cy, radi, petals) {
  var sx, sy;
  fill(242, 255, 109);
  for (var i=0; i < stopThere; i++) {
    sx = cx + radi*cos(petals*radians(i))*cos(radians(i));
    sy = cy + radi*cos(petals*radians(i))*sin(radians(i));
    ellipse(sx, sy, 3);
  }
  if ( stopThere < 720) {
    stopThere = stopThere + 1;
  }
}

function drawSpiral(cx, cy, xw, yw, radi, stop, fixed) {
  var sx, sy, sradi, xsradi;
  stroke(255);
  fill(156, 226, 210);
  sradi = 0;
  for (var i=0; i < stopHere; i++) {
    if (stopHere >= stop) {
      break;
    }
    sx = cx + xw*(yw/7)*sradi*sin(radians(i));
    sy = cy + yw*sradi*cos(radians(i));
    ellipse(sx, sy, xsradi/5, xsradi/5);
    if(fixed===true){
      xsradi=sradi;
      sradi = sradi + radi/620;
    }
    else{
      xsradi = fixed;
      sradi = sradi + radi/620;
    }
  }

  if ( stopHere < stop) {
    stopHere = stopHere + 1;
  }
}
function draw() {
  strokeWeight(0);
  drawSpiral(200,330, 5.5,8.5, 40, 220, true);
  drawSpiral(200,330, 5.5,8.5, 60, 200, true);
  drawSpiral(200,330, 5.5,8.5, 80, 215, true);
  drawSpiral(200,330, 5.5,8.5, 100, 190, true);
  drawSpiral(200,330, 5.5,8.5, 120, 160, true);
  drawSpiral(200,330, 7,1/7, 120, 720, 10);
  drawFlower(146,232,30,4);
  drawFlower(160,176,20,5);
  drawFlower(100,134,40,7);
  drawFlower(170,76,44,8);
  drawFlower(285,103,40,4);

}
