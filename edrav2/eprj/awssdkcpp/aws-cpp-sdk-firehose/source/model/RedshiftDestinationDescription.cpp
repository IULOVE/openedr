/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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

#include <aws/firehose/model/RedshiftDestinationDescription.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Firehose
{
namespace Model
{

RedshiftDestinationDescription::RedshiftDestinationDescription() : 
    m_roleARNHasBeenSet(false),
    m_clusterJDBCURLHasBeenSet(false),
    m_copyCommandHasBeenSet(false),
    m_usernameHasBeenSet(false),
    m_retryOptionsHasBeenSet(false),
    m_s3DestinationDescriptionHasBeenSet(false),
    m_processingConfigurationHasBeenSet(false),
    m_s3BackupMode(RedshiftS3BackupMode::NOT_SET),
    m_s3BackupModeHasBeenSet(false),
    m_s3BackupDescriptionHasBeenSet(false),
    m_cloudWatchLoggingOptionsHasBeenSet(false)
{
}

RedshiftDestinationDescription::RedshiftDestinationDescription(JsonView jsonValue) : 
    m_roleARNHasBeenSet(false),
    m_clusterJDBCURLHasBeenSet(false),
    m_copyCommandHasBeenSet(false),
    m_usernameHasBeenSet(false),
    m_retryOptionsHasBeenSet(false),
    m_s3DestinationDescriptionHasBeenSet(false),
    m_processingConfigurationHasBeenSet(false),
    m_s3BackupMode(RedshiftS3BackupMode::NOT_SET),
    m_s3BackupModeHasBeenSet(false),
    m_s3BackupDescriptionHasBeenSet(false),
    m_cloudWatchLoggingOptionsHasBeenSet(false)
{
  *this = jsonValue;
}

RedshiftDestinationDescription& RedshiftDestinationDescription::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("RoleARN"))
  {
    m_roleARN = jsonValue.GetString("RoleARN");

    m_roleARNHasBeenSet = true;
  }

  if(jsonValue.ValueExists("ClusterJDBCURL"))
  {
    m_clusterJDBCURL = jsonValue.GetString("ClusterJDBCURL");

    m_clusterJDBCURLHasBeenSet = true;
  }

  if(jsonValue.ValueExists("CopyCommand"))
  {
    m_copyCommand = jsonValue.GetObject("CopyCommand");

    m_copyCommandHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Username"))
  {
    m_username = jsonValue.GetString("Username");

    m_usernameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("RetryOptions"))
  {
    m_retryOptions = jsonValue.GetObject("RetryOptions");

    m_retryOptionsHasBeenSet = true;
  }

  if(jsonValue.ValueExists("S3DestinationDescription"))
  {
    m_s3DestinationDescription = jsonValue.GetObject("S3DestinationDescription");

    m_s3DestinationDescriptionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("ProcessingConfiguration"))
  {
    m_processingConfiguration = jsonValue.GetObject("ProcessingConfiguration");

    m_processingConfigurationHasBeenSet = true;
  }

  if(jsonValue.ValueExists("S3BackupMode"))
  {
    m_s3BackupMode = RedshiftS3BackupModeMapper::GetRedshiftS3BackupModeForName(jsonValue.GetString("S3BackupMode"));

    m_s3BackupModeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("S3BackupDescription"))
  {
    m_s3BackupDescription = jsonValue.GetObject("S3BackupDescription");

    m_s3BackupDescriptionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("CloudWatchLoggingOptions"))
  {
    m_cloudWatchLoggingOptions = jsonValue.GetObject("CloudWatchLoggingOptions");

    m_cloudWatchLoggingOptionsHasBeenSet = true;
  }

  return *this;
}

JsonValue RedshiftDestinationDescription::Jsonize() const
{
  JsonValue payload;

  if(m_roleARNHasBeenSet)
  {
   payload.WithString("RoleARN", m_roleARN);

  }

  if(m_clusterJDBCURLHasBeenSet)
  {
   payload.WithString("ClusterJDBCURL", m_clusterJDBCURL);

  }

  if(m_copyCommandHasBeenSet)
  {
   payload.WithObject("CopyCommand", m_copyCommand.Jsonize());

  }

  if(m_usernameHasBeenSet)
  {
   payload.WithString("Username", m_username);

  }

  if(m_retryOptionsHasBeenSet)
  {
   payload.WithObject("RetryOptions", m_retryOptions.Jsonize());

  }

  if(m_s3DestinationDescriptionHasBeenSet)
  {
   payload.WithObject("S3DestinationDescription", m_s3DestinationDescription.Jsonize());

  }

  if(m_processingConfigurationHasBeenSet)
  {
   payload.WithObject("ProcessingConfiguration", m_processingConfiguration.Jsonize());

  }

  if(m_s3BackupModeHasBeenSet)
  {
   payload.WithString("S3BackupMode", RedshiftS3BackupModeMapper::GetNameForRedshiftS3BackupMode(m_s3BackupMode));
  }

  if(m_s3BackupDescriptionHasBeenSet)
  {
   payload.WithObject("S3BackupDescription", m_s3BackupDescription.Jsonize());

  }

  if(m_cloudWatchLoggingOptionsHasBeenSet)
  {
   payload.WithObject("CloudWatchLoggingOptions", m_cloudWatchLoggingOptions.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace Firehose
} // namespace Aws
