#ifndef FIGURE_LIST_H
#define FIGURE_LIST_H

#include "figure.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class figure_list : public figure {
    public:
        std::vector<shared_ptr<figure>> attri_List;

    public:
        figure_list() {}
        figure_list(shared_ptr<figure> object) { add(object); } // ajoute une figure a object

        void clear() { attri_List.clear(); }
        void add(shared_ptr<figure> object) { attri_List.push_back(object); }

        bool hit(const obj_Ray& ray, double t_min, double t_max, obj_Record& record) const;
};

bool figure_list::hit(const obj_Ray& ray, double t_min, double t_max, obj_Record& record) const {
    obj_Record temp_record;
    bool find = false;
    double closest = t_max;

    for (const shared_ptr<figure>& object : attri_List) {
        if (object -> hit(ray, t_min, closest, temp_record)) {
            find = true;
            closest = temp_record.attri_t;
            record = temp_record;
        }
    }

    return find;
}

#endif