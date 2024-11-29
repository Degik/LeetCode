vector<int> breakingRecords(vector<int> scores) {
    int worst_count = 0;
    int best_count = 0;
    int n = scores.size();
    int max_elem = 0, min_elem = INT32_MAX;
    for(int i = 0; i < n; i++){
        int score = scores[i];
        int old_min = min_elem, old_max = max_elem;
        min_elem = min(min_elem, score);
        max_elem = max(max_elem, score);
        // Start counting possible difference
        if(i != 0){
            // Check if the min record changed
            if(old_min != min_elem){
                worst_count++;
            }
            if(old_max != max_elem){
                best_count++;
            }
        }
    }
    vector<int> result;
    result.push_back(best_count);
    result.push_back(worst_count);
    return result;
}
