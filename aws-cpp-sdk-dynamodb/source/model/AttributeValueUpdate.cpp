/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/dynamodb/model/AttributeValueUpdate.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::DynamoDB::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

AttributeValueUpdate::AttributeValueUpdate() : 
    m_valueHasBeenSet(false),
    m_actionHasBeenSet(false)
{
}

AttributeValueUpdate::AttributeValueUpdate(const JsonValue& jsonValue) : 
    m_valueHasBeenSet(false),
    m_actionHasBeenSet(false)
{
  *this = jsonValue;
}

AttributeValueUpdate& AttributeValueUpdate::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("Value"))
  {
    m_value = jsonValue.GetObject("Value");

    m_valueHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Action"))
  {
    m_action = AttributeActionMapper::GetAttributeActionForName(jsonValue.GetString("Action"));

    m_actionHasBeenSet = true;
  }

  return *this;
}

JsonValue AttributeValueUpdate::Jsonize() const
{
  JsonValue payload;

  if(m_valueHasBeenSet)
  {
   payload.WithObject("Value", m_value.Jsonize());

  }

  if(m_actionHasBeenSet)
  {
   payload.WithString("Action", AttributeActionMapper::GetNameForAttributeAction(m_action));
  }

  return payload;
}