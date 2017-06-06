function setup() {
  createCanvas(400, 400);
  background(255);

  //sun
  noStroke();
  for (var y=0; y < height; y+= 4) {
    for (var x=0; x < width; x+=4) {
      if (impl_circ(3*width/4, height/5, 50, x, y) < 0.0) {
        fill(random(220, 245), random(200, 220), random(10, 35));
        if (impl_circ(3*width/4, height/5, 35, x, y) < 0.0) {
          fill(random(230, 250), random(210, 225), random(100, 150));
          if (impl_circ(3*width/4, height/5, 20, x, y) < 0.0) {
            fill(random(230, 250), random(230, 245), random(220, 250));
          }
        }
      }
      //sky
      else {
        fill(random(150, 200), random(230, 255), random(220, 250));
      }
      ellipse(x, y, 15, 8);
    }
  }

}

function impl_circ(cx, cy, radi, in_x, in_y) {
  return ( (in_x-cx)*(in_x-cx) + (in_y-cy)*(in_y-cy) - radi*radi);
}

function impl_line(x1, y1, x2, y2, in_x, in_y) {
  return ( (y2-y1)*in_x + (x2-x1)*in_y + x1*y2 - x2*y1 );
}


function draw() {
  //grass
  for (var gy=0; gy < height+10; gy+= 2) {
    for (var gx=0; gx < width; gx+=2) {
      if (0 < impl_line(0, 250, 400, 250, gx, gy)) {
        fill(random(50, 120), random(150, 240), random(30, 80));
        stroke(random(50, 120), random(150, 240), random(30, 80));
        strokeWeight(1);
        line(gx, gy, gx-random(0,3), gy-random(5,25));
      }
    }
  }

  for (var y=0; y < height; y+= 1) {
    for (var x=0; x < width; x+=1) {
      if (impl_circ(1*width/4 + 30, 12*height/5, 100, x, 3*y) < 0.0) {
        noStroke();
        fill(random(30, 60), random(30, 150), random(150,255));
        ellipse(x, y, 6, 3);
      }
    }
  }

}
