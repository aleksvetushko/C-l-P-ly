//Example of very simple particle systems - inroduction to objects in javascript

//define a single particle
var Rs, Gs, Bs;
function Particle(x , y)
{
   //the data associated with a particle
   this.accelY = 0.05; //gravity
   this.velX = random(-1, 1);
   this.velY = random(-3, -4);
   //note this particle only can vary its blue color - change this to include red and green
   this.pcolorB = random(Bs-20, Bs+20);
   this.pcolorR = random(Rs-20, Rs+20);
   this.pcolorG = random(Gs-20, Gs+20);
   this.locX = x;
   this.locY = y;
   this.rw = 8.0;
   this.rh = 8.0;
   this.life = 100;
   this.time = 0;

   //a function to update the particle each frame
   this.updateP = function()
   {
      this.velY += this.accelY;
      this.locX += this.velX;
      this.locY += this.velY;
      this.life -= .5;
      this.time +=1.0;
      if (this.time%50<25) {
        this.rw += 2.0;
        this.rh -= 2.0;
      }
      else {
        this.rw -= 2.0;
        this.rh += 2.0;
      }
   };

   //function to draw a particle
   this.renderP = function()
   {
      noStroke();
      push();
         ellipseMode(CENTER);
         //very simple coloring
         fill(this.pcolorR-this.time/2, this.pcolorG+this.time/2, this.pcolorB, this.life);
         translate(this.locX, this.locY);
         ellipse(0, 0, this.rw, this.rh);
      pop();
   };
} //end of particle object definition


//define a group of particles as a particleSys
function PSys(sX, sY, num)
{
    //the data - lots of particles
   this.particles = [];
   Rs = random(20,235);
   Gs = random(20,235);
   Bs = random(20,235);
   for (var i=0; i < num; i++)
   {
      this.particles.push(new Particle(sX, sY));
   }

    //function defining what to do each frame
   this.run = function()
   {
      for (var i=0; i < this.particles.length; i++)
      {
         //update each particle per frame
         this.particles[i].updateP();
         this.particles[i].renderP();
      }
   }
}

//declare of a variable to represent a particle system
var fireW1;

function setup()
{
   createCanvas(500, 500);
   colorMode(RGB, 255, 255, 255, 100);
   frameRate(40);

   //start a new particle system
   fireW1 = new PSys(mouseX, mouseY, 20);
}

var works = [];

function mouseClicked() {
  works.push(new PSys(mouseX, mouseY, 20));
}

function draw()
{
   background(0);

   //run the particle system
   for(var i = 0; i < works.length; i++) {
     works[i].run();
   }
}
