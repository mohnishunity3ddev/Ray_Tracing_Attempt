#if !defined(NOISE_TEXTURE_H)

#include "defines.h"
#include "Perlin.h"
#include "Texture.h"

class noise_texture : public texture
{
  public:
    noise_texture() : noise(perlin()) {}
    noise_texture(f64 Frequency) : frequency(Frequency), noise(perlin()) {}
    
    color
    Value(f64 U, f64 V, const vec3d &P) const override
    {
#define USE_TURBULENCE 1
#if !USE_TURBULENCE
        color Result = 0.5*Color(1, 1, 1)*(1.0 + noise.Noise(frequency*P));
#else

        color Result = Color(1, 1, 1)*noise.Turbulence(frequency*P);
#endif
        
        return Result;
    }
    
    perlin PerlinNoise() { return noise; }
  
  private:
    perlin noise;
    f64 frequency;
};

#define NOISE_TEXTURE_H
#endif