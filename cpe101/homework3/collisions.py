import data
import math
import utility
import vector_math

def sphere_intersection_point(theRay, theSphere):
   dotvector_of_raydir_sqr = vector_math.dot_vector(theRay.dir, theRay.dir)
   diffpoint_of_raypt_sphcen = vector_math.difference_point(theRay.pt, theSphere.center)
   dotvector_of_raydir_diffpoint = vector_math.dot_vector(diffpoint_of_raypt_sphcen, theRay.dir)
   dotvector_of_diffpoint_sqr = vector_math.dot_vector(diffpoint_of_raypt_sphcen, diffpoint_of_raypt_sphcen)
   A = dotvector_of_raydir_sqr #(theRay.dir * theRay.dir)
   B = dotvector_of_raydir_diffpoint * 2 #(2 * (theRay.pt - theSphere.center) * theRay.dir)
   C = dotvector_of_diffpoint_sqr - theSphere.radius ** 2 #(((theRay.pt - theSphere.center) * (theRay.pt - theSphere.center)) - theSphere.radius ** 2)
   D = B ** 2 - 4 * A * C #discriminant
   if D < 0: #D < 0 means no real roots, thus sphere does not intersect with ray
      return 'None' 
   elif D == 0:
      t = (-B + math.sqrt(D)) / (2 * A)
      if t < 0:
         return 'None'
      else:
         pointt = vector_math.translate_point(theRay.pt, vector_math.scale_vector(theRay.dir, t))
         return pointt
   else:
      t1 = (-B + math.sqrt(D)) / (2 * A)
      t2 = (-B - math.sqrt(D)) / (2 * A)
      if t1 >= 0 and t2 >= 0:
         pointt = vector_math.translate_point(theRay.pt, vector_math.scale_vector(theRay.dir, min(t1, t2)))
         return pointt
      elif t1 < 0 and t2 < 0:
         return 'None'
      elif t1 < 0 or t2 < 0:
         pointt = vector_math.translate_point(theRay.pt, vector_math.scale_vector(theRay.dir, max(t1, t2)))
         return pointt

def find_intersection_points(sphere_list, ray):
   list_of_intersection_pairs = []
   for sphere in sphere_list:
      if sphere_intersection_point(ray, sphere) != 'None':
         list_of_intersection_pairs.append((sphere, sphere_intersection_point(ray, sphere)))
   return list_of_intersection_pairs
         
def sphere_normal_at_point(sphere, point):
   vector = vector_math.difference_point(point, sphere.center)
   normalvector = vector_math.normalize_vector(vector)
   return normalvector
