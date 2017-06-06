import data
import math
import utility
import vector_math
import collisions


def dplusrange(start, stop, step):
   r = start
   while r <= stop:
      yield r
      r += step
      
def dminusrange(start, stop, step):
   r = stop
   while r >= start:
      yield r
      r -= step
      
def colortop3(color):
   if color < 1:
      p3 = color * 255
   elif color >= 1.0:
      p3 = 255
   return p3

def findClosestSphere(ray, intersection_list):
   sphere1 = intersection_list[0][0]
   point1 = intersection_list[0][1]
   for spheres in intersection_list:
      sphere = spheres[0]
      intersection = spheres[1]
      minimum_dist = vector_math.length_vector(vector_math.vector_from_to(ray.pt, intersection))
      length = vector_math.length_vector(vector_math.vector_from_to(ray.pt, point1))
      if minimum_dist < length:
         sphere1 = sphere
         point1 = intersection
   return sphere1, point1

def getcolor(ray, intersection_list):
   closest = findClosestSphere(ray, intersection_list)
   sphere = closest[0]
   spherecolor = sphere.color
   return sphere.color.r, sphere.color.g, sphere.color.b

def getDiffuse(ray, intersection_list, sphere_list, light):
    closest = findClosestSphere(ray, intersection_list)
    csphere = closest[0]
    cpoint = closest[1]
    normalVec = collisions.sphere_normal_at_point(csphere, cpoint)
    scaled_vector = vector_math.scale_vector(normalVec, 0.01)
    p_e = vector_math.translate_point(cpoint, scaled_vector)
    light_vector = vector_math.vector_from_to(p_e, light.pt)
    L_dir = vector_math.normalize_vector(light_vector)
    ldotProduct = vector_math.dot_vector(normalVec, L_dir)
    light_ray = data.Ray(p_e, L_dir)
    light_intersections = collisions.find_intersection_points(sphere_list, light_ray)
    light_distance = vector_math.length_vector(light_vector)
    if_diffuse = True
    if ldotProduct > 0:
       if light_intersections != []:
          for spheres_and_points in light_intersections:
             point = spheres_and_points[1]
             difference_lengths = vector_math.length_vector(vector_math.difference_point(point, p_e))
             if difference_lengths < light_distance:
                if_diffuse = False
    else:
       if_diffuse = False
    if if_diffuse:
        lClr_r = light.color.r
        lClr_g = light.color.g
        lClr_b = light.color.b
        sp_r = csphere.color.r
        sp_g = csphere.color.g
        sp_b = csphere.color.b
        diff_r = ldotProduct * lClr_r * sp_r * csphere.finish.diffuse
        diff_g = ldotProduct * lClr_g * sp_g * csphere.finish.diffuse
        diff_b = ldotProduct * lClr_b * sp_b * csphere.finish.diffuse
    else:
        diff_r = 0
        diff_g = 0
        diff_b = 0
    return (diff_r, diff_g, diff_b)
   
def getSpecular(ray, intersection_list, light, point):
    closest = findClosestSphere(ray, intersection_list)
    csphere = closest[0]
    cpoint = closest[1]
    n_vector = collisions.sphere_normal_at_point(csphere, cpoint)
    scaled_vector = vector_math.scale_vector(n_vector, 0.01)
    p_e = vector_math.translate_point(cpoint, scaled_vector)
    light_vector = vector_math.vector_from_to(p_e, light.pt)
    L_dir = vector_math.normalize_vector(light_vector)
    light_dot_product = vector_math.dot_vector(n_vector, L_dir)
#gets spec values
    n_scale = vector_math.scale_vector(n_vector, (2*light_dot_product))
    reflection = vector_math.difference_vector(L_dir, n_scale)
    pe_eyevec = vector_math.normalize_vector(vector_math.difference_point(p_e, point))
    specularIntensity = vector_math.dot_vector(pe_eyevec, reflection)
    if specularIntensity > 0:
        sphere_spec = csphere.finish.specular
        sphere_rough = csphere.finish.roughness
        specCont_r = (light.color.r * sphere_spec) * (specularIntensity ** (1 / float(sphere_rough)))
        specCont_g = (light.color.g * sphere_spec) * (specularIntensity ** (1 / float(sphere_rough)))
        specCont_b = (light.color.b * sphere_spec) * (specularIntensity ** (1 / float(sphere_rough)))
    else:
        specCont_r = 0
        specCont_g = 0
        specCont_b = 0
    return (specCont_r, specCont_g, specCont_b)

   
def cast_ray(ray, sphere_list, color, light, point):
   intersections = collisions.find_intersection_points(sphere_list, ray)
   if intersections != []:
      colors = getcolor(ray, intersections)
      sphereR = colors[0]
      sphereG = colors[1]
      sphereB = colors[2]
      
      diffuse = getDiffuse(ray, intersections, sphere_list, light)
      sphereDR = diffuse[0]
      sphereDG = diffuse[1]
      sphereDB = diffuse[2]
      
      specular = getSpecular(ray, intersections, light, point)
      sphereSR = specular[0]
      sphereSG = specular[1]
      sphereSB = specular[2]

      closest = findClosestSphere(ray, intersections)
      closestSphere = closest[0]
      closestPoint = closest[1]
      
      finalcolorR = color.r * sphereR * closestSphere.finish.ambient + sphereDR + sphereSR
      finalcolorG = color.g * sphereG * closestSphere.finish.ambient + sphereDG + sphereSG
      finalcolorB = color.b * sphereB * closestSphere.finish.ambient + sphereDB + sphereSB

      finalcolorRGB = data.Color(finalcolorR, finalcolorG, finalcolorB)
      return finalcolorRGB
   else:
      return data.Color(1.0, 1.0, 1.0)


   

def cast_all_rays(min_x, max_x, min_y, max_y, width, height, eye_point, sphere_list, color, light):
   w = math.fabs(min_x) + math.fabs(max_x)
   changeX = w / width
   xval = [(min_x + (vals * changeX)) for vals in range(width)]
   yheight = math.fabs(min_y) + math.fabs(max_y)
   changeY = yheight / height
   yval = [(max_y - (vals * changeY)) for vals in range(height)]
  

   xstep = (max_x - min_x) / float(width)
   ystep = (max_y - min_y) / float(height)
   print 'P3'
   print str(width)+ ' '+str(height)
   print '255'

   for y in yval:
      for x in xval:
         ray = data.Ray(eye_point, vector_math.difference_point(data.Point(x, y, 0), eye_point))
         finalColors = cast_ray(ray, sphere_list, color, light, eye_point)
         if finalColors:
            print str(int(finalColors.r * 255)) + ' ' + str(int(finalColors.g * 255)) + ' ' + str(int(finalColors.b * 255))
         else:
            print '255 255 255'
