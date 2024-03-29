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

/*************************************************************************************
 * Includes                                                                          *
 *************************************************************************************/
#include "safe-link.hpp"
#include <memory>
#include <string>

#include <iostream>

/*************************************************************************************
 * Typedefs                                                                          *
 *************************************************************************************/
class Record : NonCopyable, NonMovable
{
public:
    Record(const std::string& id, const std::string& name) :
        m_id(id),
        m_name(name)
    {

    }

    ~Record()
    {

    }

    const std::string id() const
    {
        return m_id;
    }

    const std::string name() const
    {
        return m_name;
    }

private:
    std::string    m_id;
    std::string    m_name;
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

int main(void)
{
    SafeLink<std::shared_ptr<Record>>    safeList;
    std::shared_ptr<Record>    x = std::make_shared<Record>("01", "one");
    safeList.push(x);
    safeList.push(std::make_shared<Record>("02", "two"));

    std::shared_ptr<Record> first = safeList.pop();

    std::cout << "id : " << first->id() << ", name : " << first->name() << std::endl;

    first = safeList.pop();

    std::cout << "id : " << first->id() << ", name : " << first->name() << std::endl;

    return 0;
}

/* EOF */
