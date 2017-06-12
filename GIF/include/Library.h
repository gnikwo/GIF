#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <map>


using namespace std;

namespace GIF
{

    template <class T>
        class Library
        {

            public:

                Library(): m__objects()
                {



                }

                /** Copy constructor
                 * @param other, Library lvalue reference to copy
                 */
                Library(const Library& other): Library()
                {

                    for(auto it : other.m__objects)
                    {

                        m__objects.insert(std::pair<decltype(it.first), T*>(it.fist, new T(it.second)) );

                    }

                }

                /** Move constructor
                 * @param other, Library rvalue to move
                 */
                Library(Library&& other): Library()
                {

                    swap(*this, other);

                }

                ~Library()
                {

                    flush();

                }

                friend void swap(Library& a, Library& b)
                {

                    using std::swap;

                    std::swap(a.map, b.map);

                }

                Library& operator=(const Library& other)
                {

                    Library temp(other);

                    swap(*this, other);

                }


                Library& operator=(Library&& other)
                {

                    swap(*this, other);

                }


                bool has(std::string path)
                {

                    return m__objects.find(path) != m__objects.end();

                }

                void add(std::string path, T* object)
                {

                    m__objects.insert(pair<string, T*>(path, object));

                }

                T* get(std::string path)
                {

                    return m__objects.at(path);

                }

                void flush()
                {

                    for(auto iter: m__objects)
                        delete(iter.second);

                    m__objects.clear();

                }


                std::map<std::string, T*> getMap()
                {

                    return m__objects;

                }

            private:

                std::map<std::string, T*> m__objects;

        };

}

#endif
