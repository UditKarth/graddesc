#ifndef GENERALIZED_NORMALIZED_GRADIENT_ALGORITHM_H
#define GENERALIZED_NORMALIZED_GRADIENT_ALGORITHM_H

#include <vector>
#include <fstream>
#include <sstream>
#include <string>

class GeneralizedNormalizedGradientAlgorithm {
public:
    // Function to initialize parameters
    std::vector<double> initialize_parameters();

    // Function to compute cost
    double compute_cost(const std::vector<std::vector<double>>& data_points,
                        const std::vector<double>& parameters,
                        const std::vector<double>& target_values);

    // Function to compute gradient
    std::vector<double> compute_gradient(const std::vector<std::vector<double>>& data_points,
                                         const std::vector<double>& parameters,
                                         const std::vector<double>& target_values);

    // Function to update parameters
    std::vector<double> update_parameters(const std::vector<double>& current_parameters,
                                         const std::vector<double>& gradient,
                                         double learning_rate);

    // Function to perform gradient descent
    std::vector<double> gradient_descent(const std::vector<std::vector<double>>& data_points,
                                         const std::vector<double>& target_values,
                                         const std::vector<double>& initial_parameters,
                                         double learning_rate,
                                         int max_iterations,
                                         double convergence_threshold);

private:
    // Define any additional helper functions or variables as needed
    bool check_convergence(const std::vector<double>& new_parameters,
                       const std::vector<double>& old_parameters,
                       double threshold);
    std::vector<std::vector<double>> normalize_data(const std::vector<std::vector<double>>& data_points);

};
//Read csv data
std::vector<std::vector<double>> read_csv(const std::string& filename);



#endif // GENERALIZED_NORMALIZED_GRADIENT_ALGORITHM_H
