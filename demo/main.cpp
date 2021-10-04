#include <header.hpp>
#include <cmath>

void experiment(std::vector<double>& batch,
                L_Cache::run_func f) {
  unsigned mb = pow(2, 18);

  //First run
  L_Cache ex_one = L_Cache(16384);
  ex_one.warm_up();
  batch.push_back((ex_one.*f)());

  //Second run
  L_Cache ex_two = L_Cache(mb);
  ex_two.warm_up();
  batch.push_back((ex_two.*f)());

  //Third run
  L_Cache ex_three = L_Cache(2*mb);
  ex_three.warm_up();
  batch.push_back((ex_three.*f)());

  //Fourth run
  L_Cache ex_four = L_Cache(4*mb);
  ex_four.warm_up();
  batch.push_back((ex_four.*f)());

  //Fifth run
  L_Cache ex_five = L_Cache(8*mb);
  ex_five.warm_up();
  batch.push_back((ex_five.*f)());

  //Sixth run
  L_Cache ex_six = L_Cache(16*mb);
  ex_six.warm_up();
  batch.push_back((ex_six.*f)());

  //Seventh run
  L_Cache ex_seven = L_Cache(18*mb);
  ex_seven.warm_up();
  batch.push_back((ex_seven.*f)());

}

void print_batch(const std::vector<double>& batch) {
  for(std::size_t i = 0; i < batch.size(); i++) {
    std::cout << i + 1 << " run: [" << batch[i] * 1000 << " ms]" << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<double> batch1 = {};
  std::vector<double> batch2 = {};
  std::vector<double> batch3 = {};

  //Straight series
  experiment(batch1, &L_Cache::straight);
  std::cout << "++++++++++ Straight series ++++++++++" << std::endl;
  print_batch(batch1);

  //Back series
  experiment(batch2, &L_Cache::back);
  std::cout << "++++++++++++ Back series ++++++++++++" << std::endl;
  print_batch(batch2);

  //Random series
  experiment(batch3, &L_Cache::random);
  std::cout << "+++++++++++ Random series +++++++++++" << std::endl;
  print_batch(batch3);
  return 0;
}
