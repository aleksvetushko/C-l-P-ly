var max_theta;

function setup()
{
   createCanvas(400, 400);
   background(0);
   fill(255);
   noStroke();

   max_theta = 0;
}

function draw()
{
   var x, y, theta, c1, c2, c3;
	 c1=c2=c3=10;

   for (theta = 0; theta < max_theta; theta += 2*PI/300)
   {
		 fill(color(c1, c2, c3));
		 	x = 200+  200 * sin(.9*theta);
			y = 200+  200 * sin(theta);

      ellipse(x, y, 3);
			c1+=.05;c2+=.2;c3+=.1;
   }
		 max_theta += 4*PI/300;
	 if (max_theta > 70) {
	 	noLoop();
	 }
}
