#pragma

#include <cstdint>
#include <cmath>

namespace ca_model::utils {
    template <typename T, int Size>
    class circularQueuePtr {
        private:
            int ptr_width = std::log2(Size);
            bool flag;
            T val;

        public:

        circularQueuePtr() {
            flag = false;
            val = 0;
        }

        circularQueuePtr(bool f, T v) {
            flag = f;
            val = v;
        }

        ~circularQueuePtr() {}

        circularQueuePtr operator+(T data) {
            if ((val+data) >= (Size - 1)) {
                this->flag = !flag;
            }
            this->val = (this->val + data) % Size;
            return *this;
        }

        circularQueuePtr operator-(T data) {
            if ((val - data) <= 0) {
                this->flag = !flag;
            }
            this->val = (this->val - data) % Size;
            return *this;
        }

        bool operator==(const circularQueuePtr& other) {
            return (flag == other.flag) && (val == other.val);
        }

        bool operator!=(const circularQueuePtr& other) {
            return (flag != other.flag) || (val != other.val);
        }

        bool operator<(const circularQueuePtr& other) {
            bool diff_flag = flag ^ other.flag;
            bool cmp = val < other.val;
            return diff_flag ^ cmp;
        }

        bool operator>(const circularQueuePtr& other) {
            bool diff_flag = flag ^ other.flag;
            bool cmp = val > other.val;
            return diff_flag ^ cmp;
        }

        bool operator>=(const circularQueuePtr& other) {
            bool diff_flag = flag ^ other.flag;
            bool cmp = val >= other.val;
            return diff_flag ^ cmp;
        }
    };
};