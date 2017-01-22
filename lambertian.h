#ifndef LAMBERTIAN_H_
#define LAMBERTIAN_H_
#include "material.h"

vec3 random_point_in_sphere() {
  vec3 point;
  do {
    point = vec3(drand48(), drand48(), drand48())*2.0 - vec3(1,1,1);
  } while (dot(point, point) >= 1.0);
  return point;
}

class lambertian : public material {
public:
  vec3 albedo;
  lambertian(const vec3& a) : albedo(a) {}
  virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
    vec3 target = rec.p + rec.normal + random_point_in_sphere();
    scattered = ray(rec.p, target-rec.p);
    attenuation = albedo;
    return true;
  }
};

#endif