# Generated by the protocol buffer compiler.  DO NOT EDIT!

from google.protobuf import descriptor
from google.protobuf import message
from google.protobuf import reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)


import device_management_backend_pb2

DESCRIPTOR = descriptor.FileDescriptor(
  name='device_management_local.proto',
  package='enterprise_management',
  serialized_pb='\n\x1d\x64\x65vice_management_local.proto\x12\x15\x65nterprise_management\x1a\x1f\x64\x65vice_management_backend.proto\"\xc7\x01\n\x19\x43\x61\x63hedCloudPolicyResponse\x12\x42\n\rdevice_policy\x18\x01 \x01(\x0b\x32+.enterprise_management.DevicePolicyResponse\x12\x11\n\ttimestamp\x18\x02 \x01(\x04\x12\x11\n\tunmanaged\x18\x03 \x01(\x08\x12@\n\x0c\x63loud_policy\x18\x04 \x01(\x0b\x32*.enterprise_management.PolicyFetchResponse\"<\n\x11\x44\x65viceCredentials\x12\x11\n\tdevice_id\x18\x01 \x01(\t\x12\x14\n\x0c\x64\x65vice_token\x18\x02 \x01(\tB\x02H\x03')




_CACHEDCLOUDPOLICYRESPONSE = descriptor.Descriptor(
  name='CachedCloudPolicyResponse',
  full_name='enterprise_management.CachedCloudPolicyResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='device_policy', full_name='enterprise_management.CachedCloudPolicyResponse.device_policy', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='timestamp', full_name='enterprise_management.CachedCloudPolicyResponse.timestamp', index=1,
      number=2, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='unmanaged', full_name='enterprise_management.CachedCloudPolicyResponse.unmanaged', index=2,
      number=3, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='cloud_policy', full_name='enterprise_management.CachedCloudPolicyResponse.cloud_policy', index=3,
      number=4, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=90,
  serialized_end=289,
)


_DEVICECREDENTIALS = descriptor.Descriptor(
  name='DeviceCredentials',
  full_name='enterprise_management.DeviceCredentials',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    descriptor.FieldDescriptor(
      name='device_id', full_name='enterprise_management.DeviceCredentials.device_id', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    descriptor.FieldDescriptor(
      name='device_token', full_name='enterprise_management.DeviceCredentials.device_token', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=291,
  serialized_end=351,
)

_CACHEDCLOUDPOLICYRESPONSE.fields_by_name['device_policy'].message_type = device_management_backend_pb2._DEVICEPOLICYRESPONSE
_CACHEDCLOUDPOLICYRESPONSE.fields_by_name['cloud_policy'].message_type = device_management_backend_pb2._POLICYFETCHRESPONSE
DESCRIPTOR.message_types_by_name['CachedCloudPolicyResponse'] = _CACHEDCLOUDPOLICYRESPONSE
DESCRIPTOR.message_types_by_name['DeviceCredentials'] = _DEVICECREDENTIALS

class CachedCloudPolicyResponse(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _CACHEDCLOUDPOLICYRESPONSE
  
  # @@protoc_insertion_point(class_scope:enterprise_management.CachedCloudPolicyResponse)

class DeviceCredentials(message.Message):
  __metaclass__ = reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _DEVICECREDENTIALS
  
  # @@protoc_insertion_point(class_scope:enterprise_management.DeviceCredentials)

# @@protoc_insertion_point(module_scope)
