#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string> // For string manipulation
using namespace std;

vector<int> input_history;

// Helper to calculate the most frequent number
int most_frequent(const vector<int>& history) {
    map<int, int> frequency;
    for (int num : history) {
        frequency[num]++;
    }

    auto max_iter = max_element(frequency.begin(), frequency.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

    return max_iter->first;
}

// Predict the next number based on the trend (e.g., if the numbers are increasing, predict the next in sequence)
int predict_next() {
    if (input_history.empty()) {
        return 50; // Default guess
    }

    int n = input_history.size();
    int last = input_history[n - 1];

    // Check for increasing sequence
    if (n >= 2) {
        int second_last = input_history[n - 2];
        if (last > second_last) { // Detect if numbers are increasing
            return last + 1; // Predict the next number as the next in sequence
        }
    }

    return last; // Default to the last number if no sequence is detected
}

int main() {
    while (true) {
        int userNumber;
        cout << "Enter a number between 1 and 100 (or 0 to quit): ";
        cin >> userNumber;

        if (userNumber == 0) {
            cout << "Thanks for playing! Goodbye!" << endl;
            break;
        }

        if (userNumber < 1 || userNumber > 100) {
            cout << "Invalid input. Please enter a number between 1 and 100." << endl;
            continue;
        }

        // First, predict the next number based on the sequence
        int programPrediction = predict_next();
        cout << "The program predicts: " << programPrediction << endl;

        // Now, add the user's input to the history
        input_history.push_back(userNumber);

        // Compare the prediction with the user's input
        if (programPrediction == userNumber) {
            cout << "Program wins!" << endl;
        }
        else {
            cout << "Program loses!" << endl;
        }

        cout << "================================" << endl;
        cout << "Your input history:" << endl;
        for (int num : input_history) {
            cout << num << " ";
        }
        cout << endl;
        cout << "================================" << endl;
    }

    return 0;
}
