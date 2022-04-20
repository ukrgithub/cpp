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

#ifndef   __CPP_RULE_H__
#define   __CPP_RULE_H__

/*************************************************************************************
 * Includes                                                                          *
 *************************************************************************************/

/*************************************************************************************
 * Typedefs                                                                          *
 *************************************************************************************/
class NonCopyable
{
private:
    NonCopyable(const NonCopyable& other) = delete;
    NonCopyable& operator=(const NonCopyable& other) = delete;

protected:
    NonCopyable() = default;
    ~NonCopyable() = default;
};

class NonMovable
{
private:
    NonMovable(const NonMovable&& other) = delete;
    NonMovable& operator=(const NonMovable&& other) = delete;

protected:
    NonMovable() = default;
    ~NonMovable() = default;
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


#endif   /*! __CPP_RULE_H__ */
