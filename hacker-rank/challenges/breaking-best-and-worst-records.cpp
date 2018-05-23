#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the breakingRecords function below.
vector<int> breakingRecords(vector<int> &score) {
    int min = score[0];
    int max = score[0];
    vector<int> r {0, 0};
    for(auto& s : score){
        if(s > max){
            max = s;
            r[0]++;
        }
        if(s < min){
            min = s;
            r[1]++;
        }
    }
    
    return r;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string score_temp_temp;
    getline(cin, score_temp_temp);

    vector<string> score_temp = split_string(score_temp_temp);

    vector<int> score(n);

    for (int i = 0; i < n; i++) {
        int score_item = stoi(score_temp[i]);

        score[i] = score_item;
    }

    vector<int> result = breakingRecords(score);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
