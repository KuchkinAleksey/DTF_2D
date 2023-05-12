#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

const double PI = 3.14159265358979;
const std::string kResourcesDir = "../resources/";

int main()
{

  int w, h, comp=1;
  const uint8_t *img = stbi_load((kResourcesDir+std::string("lena.png")).c_str(), &w, &h, NULL, comp);
  if (img == nullptr) 
  {
    std::cerr << "Error in loading the image\n";
    return 1;
  }

  // alloc
  uint32_t len = w*h;
  double *Mag = new double[len];
  double mag_min=1e9, mag_max=-1e9;

  int dT_x = w / 20;
  int dT_y = h / 20;

  // dtf 2d
  for (int j=0; j<h; ++j) {
    for (int i=0; i<w; ++i) {
      uint32_t idx = j*w+i;
      double Re = 0.0;
      double Im = 0.0;
      for (int l=0; l<h; l+=dT_x) {
        for (int k=0; k<w; k+=dT_y) {
          uint32_t idx_sh = l*w+k;
          double x = 2.0*PI*(1.0*k*i/w + 1.0*l*j/h);
          Re += img[idx_sh]*std::cos(x);
          Im -= img[idx_sh]*std::sin(x);
        }      
      }
      Mag[idx] = std::log(1.0 + std::sqrt(Re*Re+Im*Im));
      if (Mag[idx] > mag_max) mag_max = Mag[idx];
      if (Mag[idx] < mag_min) mag_min = Mag[idx];

      std::cout << idx+1 << "/" << len << " " << Re << " + " << Im << "j" << "\n";
    }
  }

  uint8_t *out = new uint8_t[len];

  // norm min_max -> swap quadrants for (0,0) centering -> cast 
  for (int j=0; j<h; ++j) {
    for (int i=0; i<w; ++i) {
      int x = i < w/2 ? i+w/2 : i-w/2;
      int y = j < h/2 ? j+h/2 : j-h/2;
      uint32_t idx = j*w+i;
      uint32_t quad_idx = y*w+x;
      out[idx] = uint8_t(255.0 * ((Mag[quad_idx] - mag_min)/(mag_max-mag_min)));
    }
  }

  stbi_write_png((kResourcesDir+std::string("out.png")).c_str(), w, h, comp, out, w);

  std::getchar();

  return 0; 
}