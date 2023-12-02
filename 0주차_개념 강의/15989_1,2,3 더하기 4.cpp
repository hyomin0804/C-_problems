#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string canHangBanner(int n, int m, const vector<int>& heights) {
    int threshold = (9 * m) / 10;  // Threshold for the number of equal heights in M consecutive segments
    
    unordered_map<int, int> count;  // Map to store the count of heights in the current M segments
    
    // Initialize the count for the first M segments
    for (int i = 0; i < m; ++i) {
        count[heights[i]]++;
    }
    
    // Check if the initial condition is met
    for (const auto& entry : count) {
        if (entry.second >= threshold) {
            return "YES";
        }
    }
    
    // Iterate over the rest of the segments
    for (int i = m; i < n; ++i) {
        count[heights[i - m]]--;  // Remove the height leaving the current M segments
        count[heights[i]]++;  // Add the new height entering the current M segments
        
        // Check if the condition is met in the current M segments
        for (const auto& entry : count) {
            if (entry.second >= threshold) {
                return "YES";
            }
        }
    }
    
    return "NO";
}

int main() {
    // Read input
    int n, m;
    cin >> n >> m;
    
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    
    // Check if a banner can be hung
    string result = canHangBanner(n, m, heights);
    
    // Print the result
    cout << result << endl;
    
    return 0;
}

