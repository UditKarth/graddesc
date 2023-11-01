#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "generalized_normalized_gradient_algorithm.h" // Include your header file

// Test case for initialize_parameters function
TEST_CASE("Test initialize_parameters", "[weight=1][part=1]") {
    int expected_size = 5;
    GeneralizedNormalizedGradientAlgorithm algorithm;
    std::vector<double> parameters = algorithm.initialize_parameters();

    REQUIRE(parameters.size() == expected_size);
}

// Test case for compute_cost function
TEST_CASE("Test compute_cost", "[weight=1][part=1]") {
    GeneralizedNormalizedGradientAlgorithm algorithm;
    std::vector<std::vector<double>> data_points = {/*...*/}; // Define your data points
    std::vector<double> parameters = {/*...*/}; // Define your parameters
    std::vector<double> target_values = {/*...*/}; // Define your target values

    double cost = algorithm.compute_cost(data_points, parameters, target_values);
    REQUIRE(cost >= 0);
    REQUIRE(cost == expected_cost);
}

// Test case for compute_gradient function
TEST_CASE("Test compute_gradient", "[weight=1][part=1]") {
    GeneralizedNormalizedGradientAlgorithm algorithm;
    std::vector<std::vector<double>> data_points = {/*...*/}; // Define your data points
    std::vector<double> parameters = {/*...*/}; // Define your parameters
    std::vector<double> target_values = {/*...*/}; // Define your target values

    std::vector<double> gradient = algorithm.compute_gradient(data_points, parameters, target_values);
    REQUIRE(gradient.size() == 14);

}

// Test case for update_parameters function
TEST_CASE("Test update_parameters", "[weight=1][part=1]") {
    GeneralizedNormalizedGradientAlgorithm algorithm;
    std::vector<double> current_parameters = {/*...*/}; // Define your current parameters
    std::vector<double> gradient = {/*...*/}; // Define your computed gradient
    double learning_rate = 0.1; // Define your learning rate

    std::vector<double> updated_parameters = algorithm.update_parameters(current_parameters, gradient, learning_rate);
    REQUIRE(updated_parameters.size() == 14);

}

// Test case for gradient_descent function
TEST_CASE("Test gradient_descent", "[weight=1][part=1]") {
    GeneralizedNormalizedGradientAlgorithm algorithm;
    std::vector<std::vector<double>> data_points = {/*...*/}; // Define your data points
    std::vector<double> target_values = {/*...*/}; // Define your target values
    std::vector<double> initial_parameters = {/*...*/}; // Define your initial parameters
    double learning_rate = 0.1; // Define your learning rate
    int max_iterations = 100; // Define your maximum number of iterations
    double convergence_threshold = 0.001; // Define your convergence threshold

    std::vector<double> optimized_parameters = algorithm.gradient_descent(
        data_points, target_values, initial_parameters, learning_rate, max_iterations, convergence_threshold);
    for (double param : optimized_parameters) {
        REQUIRE(param > SOME_MIN_VALUE); // e.g., -1000 if you expect values not to explode
        REQUIRE(param < SOME_MAX_VALUE); // e.g., 1000
    }
    for (size_t i = 0; i < optimized_parameters.size(); ++i) {
    REQUIRE(optimized_parameters[i] == Approx(expected_optimized_parameters[i]).margin(0.01));
    }
}
