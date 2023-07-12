// https://app.codesignal.com/challenge/CTc4DmbcnWRPuKGRZ

#include <limits.h>
#include <algorithm>

struct File {
    int id;
    int size;
    int start;
    
    File(int id, int size, int start) {
        this->id = id;
        this->size = size;
        this->start = start;
    }
};

struct Comparator {
  bool operator()(const File& a, const File& b) const {
      if (a.start == b.start) return a.size < b.size;
      return a.start < b.start;
  }
};

vector<int> solution(vector<int> sizes, vector<int> startTimes, int uploadSpeed) {
    vector<File> files;
    vector<File> queue;
    for (int i = 0; i < sizes.size(); ++i) {
        files.emplace_back(i, sizes[i], startTimes[i]);
    }
    sort(files.begin(), files.end(), Comparator());
    
    // result records
    std::map<int, int> finish;
    
    int min, next;
    float time = 0.0, sec = 0.0;
    for (int i = 0; i < files.size() || !queue.empty();) {
        if (queue.empty()) time = files[i].start;
        
        while (i < files.size() && files[i].start == time) {
            queue.emplace_back(files[i]);
            i++;
        }
        
        min = INT_MAX;
        for (auto& file: queue) {
            if (file.size < min) min = file.size;
        }
        
        next = INT_MAX;
        for (auto& file: files) {
            auto v = (file.start > time ? file.start : INT_MAX);
            if (v < next) next = v;
        }
        
        auto l = min / (float(uploadSpeed) / queue.size());
        auto r = next - time;
        sec = (l < r ? l : r);
        time += sec;
        
        for (auto& file: queue) {
            file.size -= sec * float(uploadSpeed) / queue.size();
            if (file.size == 0) finish[file.id] = std::ceil(time);
        }
        
        vector<File> filtered;
        std::copy_if(
            queue.begin(), 
            queue.end(), 
            std::back_inserter(filtered), [](const File& file) { return file.size > 0; });
        queue = filtered;
    }
    
    vector<int> results;
    for (auto& [_, time]: finish) results.push_back(time);
    return results;
}
