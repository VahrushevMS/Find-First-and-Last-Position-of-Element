#include"Header.h"

vector<int> search(vector<int>& nums, int target) {
	if (nums.size() == 0) return { -1,-1 };
	int right = nums.size() - 1;
	int left = 0;
	int flag = 0;
	vector<int> result;
	if (nums.size() == 1) {
		if (nums[0] == target) return { 0,0 };
		else return { -1,-1 };
	}
	if (nums.size() == 2 && nums[0] == target && nums[1] == target) {
		return { 0,1 };
	}
	else if ((nums.size() == 2 && nums[0] != target && nums[1] == target) || (nums.size() == 2 && nums[1] != target && nums[0] == target)) {
		if (nums[0] == target) {
			return { 0,0 };
		}
		else return { 1,1 };
	}
	else if (nums.size() == 2 && nums[0] != target && nums[1] != target) {
		return { -1,-1 };
	}
	if (nums[0] == target && nums[1] != target) {
		return { 0,0 };
	}

	if (nums[nums.size() - 1] == target && nums[nums.size() - 2] != target) { int a = nums.size() - 1; return { a,a }; }
	if (find(nums.begin(), nums.end(), target) == nums.end()) return { -1,-1 };
	while (left <= right) {
		//nums.clear();
		int mid = (right + left) / 2;
		//cout << "mid= " << mid << endl;
		if ((nums[mid] == target && nums[mid] != nums[mid - 1]) || (nums[mid] == target && nums[mid] != nums[mid + 1])) {
			result.push_back(mid);
			if ((nums[mid] == target && nums[mid] != nums[mid - 1])) {
				left = mid;
			}
			else if ((nums[mid] == target && nums[mid] != nums[mid + 1])) {
				right = mid;
			}
			if (mid + 1 == nums.size() - 1 && nums[mid + 1] == target) {
				result.push_back(mid + 1);
			}
			if (mid - 1 == 0 && nums[0] == target) {
				result.push_back(0);
			}
			//cout << "!!!!!" << endl;
			flag += 1;
			sort(result.begin(), result.end());
			if (result.size() == 2) {
				return result;
			}
		}
		else if (nums[mid] < target) {
			left = mid;
		}
		else if (nums[mid] > target) {
			right = mid;
		}
		else if (nums[mid] == target && nums[mid - 1] == target && nums[mid + 1] == target) {
			right = mid + 1;
			left = mid - 1;
			//cout << "?????" << endl;
			while (right <= nums.size() - 1 && nums[right] == target) {
				right += 1;
				//cout << right;
			}
			while (left >= 0 && nums[left] == target) {
				left -= 1;
			}
			if (result.size() != 0 && result[0] != right - 1) {
				result.push_back(right - 1);
			}
			if (result.size() == 2) {
				sort(result.begin(), result.end());
				return result;
			}
			result.push_back(left + 1);
			if (result.size() == 2) {
				sort(result.begin(), result.end());
				return result;
			}

		}
	}
	return { -1,-1 };
}
int main() {
	vector<int> arr = { 0,0,0,1,2,3 };
	int target = 0;
	vector<int> result= search(arr, target);
	for (int i = 0;i < result.size();i++) {
		cout << result[i] << " ";
	}
	
	return 0;
}