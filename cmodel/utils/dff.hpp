#pragma


#include "dff_base.hpp"


namespace ca_model::utils {
    template<typename T>
    class dff : public dff_base {
        private:
            T value;
            T next_value;
        protected:
            virtual void sync() override {
                value = next_value;
            }

            virtual void sync(bool lden) override {
                if(lden) {
                    value = next_value;
                }
            }

            virtual void reset() override {
                value = T();
                next_value = T();
            }

        public:
            dff() : dff_base() {
                value = T();
                next_value = T();
            }

            dff(T value) : dff_base() {
                this->value = value;
                this->next_value = value;
            }

            T get() {
                return value;
            }

            void set(T value) {
                next_value = value;
            }

            void dff_next() {
                sync();
            }
    };
};