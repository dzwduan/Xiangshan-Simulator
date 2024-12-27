#pragma once

#include <unordered_set>

namespace ca_model::utils {
    class dff_base{
        private:
            static std::unordered_set<dff_base*> dffs;
        protected:
            virtual void sync(bool lden) = 0;
            virtual void sync() = 0;
            virtual void reset() = 0;

        public:
            dff_base() {
                dffs.insert(this);
            }

            ~dff_base() {
                dffs.erase(this);
            }

            static void sync_all() {
                for(auto dff : dffs) {
                    dff->sync();
                }
            }

            static void reset_all() {
                for(auto dff : dffs) {
                    dff->reset();
                }
            }
    };
};