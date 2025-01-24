#include <array>
#include <vector>

template<typename T, std::size_t N>
int linearSearch(std::array<T, N> arr, T target) {
    for (std::size_t i = 0; i < N; ++i) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

template<typename T>
int linearSearch(std::vector<T> vec, T target) {
    for (std::size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

template<typename T>
int binarySearch(std::vector<T> vec, T target) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid potential overflow
        if (vec[mid] == target) {
            return mid; // Target found
        }
        else if (vec[mid] < target) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

template<typename T>
int binarySearchFirst(std::vector<T> vec, T target) {
    int left = 0;
    int right = vec.size() - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) {
            result = mid;    // Record the index
            right = mid - 1; // Move left to find the first occurrence
        }
        else if (vec[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return result;
}

template<typename T, std::size_t N>
int binarySearch(std::array<T, N> arr, T target) {
    int left = 0;
    int right = N - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids potential overflow
        if (arr[mid] == target) {
            return mid; // Target found
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

template<typename T, std::size_t N>
int binarySearchFirst(std::array<T, N> arr, T target) {
    int left = 0;
    int right = N - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;    // Record the index
            right = mid - 1; // Move left to find the first occurrence
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return result;
}
