/**
 *
 * Copyright [2021] [Karthick Rajkumar]
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef   __SAFE_LINK_H__
#define   __SAFE_LINK_H__

/*************************************************************************************
 * Includes                                                                          *
 *************************************************************************************/
#include "cpp-rule.hpp"

#include <mutex>
#include <list>

/*************************************************************************************
 * Typedefs                                                                          *
 *************************************************************************************/
template <class T>
class SafeLink : private NonCopyable, private NonMovable
{
public:
    /**< Constructor */
    SafeLink() : m_mutex()
    {

    }

    /**< Destructor */
    ~SafeLink()
    {
        clear();
    }

    /**< to push an item */
    void push(const T& item)
    {
        std::lock_guard<std::mutex>    lock(m_mutex);
        m_list.push_back(item);
    }

    /**< to pop an item */
    T pop()
    {
        T    front;
        std::lock_guard<std::mutex>    lock(m_mutex);

        if (!m_list.empty())
        {
            front = m_list.front();
            m_list.pop_front();
        }

        return front;
    }

    /**< to clear the list */
    void clear()
    {
        std::lock_guard<std::mutex>    lock(m_mutex);
        m_list.clear();
    }

    /**< to remove an item from list */
    void remove(const T& item)
    {
        std::lock_guard<std::mutex>    lock(m_mutex);
        m_list.remove(item);
    }

private:
    std::mutex        m_mutex;
    std::list<T>      m_list;
};

/*************************************************************************************
 * Local Function Prototypes                                                         *
 *************************************************************************************/

/*************************************************************************************
 * Data                                                                              *
 *************************************************************************************/

/*************************************************************************************
 * Functions                                                                         *
 *************************************************************************************/


#endif   /*! __SAFE_LINK_H__ */
