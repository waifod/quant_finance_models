# Quant Finance Models

Project containing the implementations of quantitative finance models.

Models to be implemented:
1. Black-Scholes
2. CAPM
3. VaR (Value at Risk)
4. Modern Portfolio Theory

For the first three we plan to create two implementations, one classical
and the other one using Monte-Carlo simulations.

## Steps

We need the following

1. Setup a GitHub repository.
2. A way of getting financial data in C++
3. A library for Monte Carlo simulations in C++ (maybe we don't even
   need the library; TBD, we could implement ourselves).
4. A library for regressions, and basic matrix operations (potentially
   from boost).
5. Implement the actual models
    1. Black Scholes
    2. CAPM
    3. VaR (Value at Risk)
    4. Modern Portfolio Theory
6. Implement the Monte Carlo versions of the first three.

## Components Design

We need to have a components design.

- Class `Option`.
- Derived classes for `CallOption` and `PutOption` inheriting from
  `Option`.
- An abstract class `Pricing`
```c++
class Pricing {
 public:
  Pricing(CallOption);

  getPrice
};

int main() {
  auto call_option = CallOption();
  auto call_option_pricing = Pricing(call_option);
  call_option_pricing.getPrice();
}
```
- Derived class `OptionPricing`.
- Then use the Strategy design pattern for the different pricing models.
