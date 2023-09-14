#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename T1, typename T2>
struct VirtualActionInvoker2
{
	typedef void (*Action)(void*, T1, T2, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R, typename T1>
struct VirtualFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};

struct Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54;
struct Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00;
struct Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D;
struct IEnumerable_1_tF95C9E01A913DD50575531C8305932628663D9E9;
struct IEnumerable_1_t349E66EC5F09B881A8E52EE40A1AB9EC60E08E44;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129;
struct ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A;
struct AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2;
struct AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F;
struct ClientSslConfiguration_t212ECC383B70D9C462DC423E9D3CD27C9E74A603;
struct CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2;
struct DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293;
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095;
struct HashAlgorithm_t299ECE61BBF4582B1F75734D43A96DDEC9B2004D;
struct Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D;
struct HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IEqualityComparer_tEF8F1EC76B9C8E76695BE848D41E6B147928D1C1;
struct LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859;
struct MD5_t808E6AE387D5FCC368DBB86576572C1564D17E5A;
struct MethodInfo_t;
struct NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7;
struct NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7;
struct Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8;
struct RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37;
struct String_t;
struct StringBuilder_t;
struct StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06;
struct Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct X509Certificate_t966CC553AF25AE7991F5B4C2AACBCF6C66C8F9C4;
struct X509CertificateCollection_t2900D71D188EDCA7DEB5077D36103EE5DA6805CE;
struct X509CertificateImpl_tF590E81705CE1FE152C590E5A875D4FE3BE348EF;
struct X509Chain_t2E7F88A4C97CAB82AF938F13A11354A0475469E5;
struct X509ChainImpl_tBA1BF154DB9DC321EE068BBC53C7CF43CAA2621F;
struct U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55;
struct KeysCollection_t8FF5FD8704F6F99F6FD4B8A2D27DFAEFD3880F81;
struct NameObjectEntry_t58A8B38FC7A6ABE5C83153B6C3F2696F88E7A9A2;

IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Ext_t6D7C499436D2B147B941E873C73C930E159B53D0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* HttpVersion_t2C7A10EB9472F5CBEE335426D23C90378989F10A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerable_1_t349E66EC5F09B881A8E52EE40A1AB9EC60E08E44_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_1_t73FD060C436E3C4264A734C8F8DCC01DFF6046B8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringBuilder_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* String_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral000782DE5F1D05B671170917E3CF2EE86FCE6F55;
IL2CPP_EXTERN_C String_t* _stringLiteral0B9F5C4167997CA1C1F9659AB0228EEB594BA8C3;
IL2CPP_EXTERN_C String_t* _stringLiteral10C63C8C602DD5E38BE4A758C90EBAC324CD3E69;
IL2CPP_EXTERN_C String_t* _stringLiteral11E42B7A5E1CF74E4375D71D8CE94F3D8D446DBA;
IL2CPP_EXTERN_C String_t* _stringLiteral17490F55601C1F90A7803263837FE3F21E759D69;
IL2CPP_EXTERN_C String_t* _stringLiteral1C93369986E246DFCCD8F0F4ED253F8B083E300C;
IL2CPP_EXTERN_C String_t* _stringLiteral23786080E9FF3ED506C54C7BC75ED560F8E0D17A;
IL2CPP_EXTERN_C String_t* _stringLiteral2555543242A278889EA1F704BD696770579E9304;
IL2CPP_EXTERN_C String_t* _stringLiteral2958EF457D5998322D06906E8D46C16545F1EAD8;
IL2CPP_EXTERN_C String_t* _stringLiteral2C410EB1F22365EC1A74DF0D8C89C99D53453CDD;
IL2CPP_EXTERN_C String_t* _stringLiteral31FA596F0CB831B1917230C3D7C170B60B5F0398;
IL2CPP_EXTERN_C String_t* _stringLiteral335CA71010F7EFAB270E1E0D36EFB78000B60FF2;
IL2CPP_EXTERN_C String_t* _stringLiteral3781CFEEF925855A4B7284E1783A7D715A6333F6;
IL2CPP_EXTERN_C String_t* _stringLiteral56527A2300BB0A611AE7B1418C0BFCB781C48103;
IL2CPP_EXTERN_C String_t* _stringLiteral59A9856ADD5A93479660B0DADE65D1636B473A27;
IL2CPP_EXTERN_C String_t* _stringLiteral59EF9AD20EC836CD3EF188D82C03E21009DB374B;
IL2CPP_EXTERN_C String_t* _stringLiteral606A7CE0F9FFB91FC58BD3742461F2EC0C39C4B4;
IL2CPP_EXTERN_C String_t* _stringLiteral65A0F9B64ACE7C859A284EA54B1190CBF83E1260;
IL2CPP_EXTERN_C String_t* _stringLiteral6E34E505E342A11AE48ECA3D71434F8043A88EB6;
IL2CPP_EXTERN_C String_t* _stringLiteral82EA3C9AFC08F0CECEBC1B257606B3106346FCAF;
IL2CPP_EXTERN_C String_t* _stringLiteral9C35BA15FC8288F6F7A229DD42F48D4FB70DCC2E;
IL2CPP_EXTERN_C String_t* _stringLiteral9EB642385221D006B3B8DB45C10F626FD2A3DB7C;
IL2CPP_EXTERN_C String_t* _stringLiteralA33AC456085EAEABCEC676232468748A49977DBE;
IL2CPP_EXTERN_C String_t* _stringLiteralA9AF8D13B64E63A31A01386E007E5C9CF3A6CF5B;
IL2CPP_EXTERN_C String_t* _stringLiteralAD6CD2C36915DEB6A18BCF0F46B294FC1D97072F;
IL2CPP_EXTERN_C String_t* _stringLiteralB452E2B6A53FE9D2E35664FB7EB8D18D4773223C;
IL2CPP_EXTERN_C String_t* _stringLiteralB7D1CAF9B55BE135BC8B1C459D2052FBCF135556;
IL2CPP_EXTERN_C String_t* _stringLiteralBBBCFF9559F03CF35B40795127B3BDBC6A80E8CB;
IL2CPP_EXTERN_C String_t* _stringLiteralC60811AD65D0557EF69DFB2F66D9621903D5B62A;
IL2CPP_EXTERN_C String_t* _stringLiteralD555DED7CEC14AAFD2389F4CA5DB31942645053F;
IL2CPP_EXTERN_C String_t* _stringLiteralE36C77CFC3454AF8169617B02C29C26EE456DBCD;
IL2CPP_EXTERN_C String_t* _stringLiteralE3A56BE62F0FB42D8062A17A4957C2142D815735;
IL2CPP_EXTERN_C String_t* _stringLiteralE806CD6CD3D351202351C73AC5A552506A239F67;
IL2CPP_EXTERN_C String_t* _stringLiteralE8F97FBA9104D1EA5047948E6DFB67FACD9F5B73;
IL2CPP_EXTERN_C String_t* _stringLiteralF7A27446F990E86AFC16857987F96B66843F2912;
IL2CPP_EXTERN_C String_t* _stringLiteralF94826EFCA9D0B0B714BFAF666209B973B2B4730;
IL2CPP_EXTERN_C String_t* _stringLiteralFD5D7F52F77675FA28D319961C4D67C43045195A;
IL2CPP_EXTERN_C String_t* _stringLiteralFE55A44A4569E37676CECA70D4046727B22CA6A6;
IL2CPP_EXTERN_C const RuntimeMethod* ClientSslConfiguration__ctor_mB1979618DD244BF728A013D2FDC7F8D19110F13C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ClientSslConfiguration_defaultSelectClientCertificate_mA37A39560426481E9ADA0F9DDC7617E58E9732D5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ClientSslConfiguration_defaultValidateServerCertificate_m3E2BB84D36A14CB3FA16562DD2A550D222C66AF7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Ext_Contains_TisString_t_m21F17700FD2F34406CD7C4E4606CAF47F5D9CE17_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CU3Ec_U3CinitAsDigestU3Eb__40_0_m894815231F6A859B84DBD42CED0C64A3C3405DE7_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2  : public RuntimeObject
{
	NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* ____parameters;
	int32_t ____scheme;
};
struct AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F  : public RuntimeObject
{
	uint32_t ____nonceCount;
	NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* ____parameters;
	int32_t ____scheme;
};
struct ClientSslConfiguration_t212ECC383B70D9C462DC423E9D3CD27C9E74A603  : public RuntimeObject
{
	bool ____checkCertRevocation;
	LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859* ____clientCertSelectionCallback;
	X509CertificateCollection_t2900D71D188EDCA7DEB5077D36103EE5DA6805CE* ____clientCerts;
	int32_t ____enabledSslProtocols;
	RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955* ____serverCertValidationCallback;
	String_t* ____targetHost;
};
struct CollectionBase_t44F966CC555C87F2815D668FB4586526E1C2383F  : public RuntimeObject
{
	ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* ____list;
};
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095  : public RuntimeObject
{
	int32_t ___m_codePage;
	CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2* ___dataItem;
	bool ___m_deserializedFromEverett;
	bool ___m_isReadOnly;
	EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293* ___encoderFallback;
	DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90* ___decoderFallback;
};
struct HashAlgorithm_t299ECE61BBF4582B1F75734D43A96DDEC9B2004D  : public RuntimeObject
{
	bool ____disposed;
	int32_t ___HashSizeValue;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___HashValue;
	int32_t ___State;
};
struct HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5  : public RuntimeObject
{
	String_t* ____headerName;
	int32_t ____headerType;
};
struct HttpVersion_t2C7A10EB9472F5CBEE335426D23C90378989F10A  : public RuntimeObject
{
};
struct NameObjectCollectionBase_tB6400DF2FA3B64660D79586B79016B4A0BA645FC  : public RuntimeObject
{
	bool ____readOnly;
	ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* ____entriesArray;
	RuntimeObject* ____keyComparer;
	Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* ____entriesTable;
	NameObjectEntry_t58A8B38FC7A6ABE5C83153B6C3F2696F88E7A9A2* ____nullKeyEntry;
	KeysCollection_t8FF5FD8704F6F99F6FD4B8A2D27DFAEFD3880F81* ____keys;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____serializationInfo;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7  : public RuntimeObject
{
	String_t* ____domain;
	String_t* ____password;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ____roles;
	String_t* ____username;
};
struct Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8  : public RuntimeObject
{
	int32_t ____inext;
	int32_t ____inextp;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____seedArray;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct StringBuilder_t  : public RuntimeObject
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___m_ChunkChars;
	StringBuilder_t* ___m_ChunkPrevious;
	int32_t ___m_ChunkLength;
	int32_t ___m_ChunkOffset;
	int32_t ___m_MaxCapacity;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7  : public RuntimeObject
{
	int32_t ____Major;
	int32_t ____Minor;
	int32_t ____Build;
	int32_t ____Revision;
};
struct WebSocketContext_t864B980CACE6C6D128960E555404BC87E7A4C3F2  : public RuntimeObject
{
};
struct X509Chain_t2E7F88A4C97CAB82AF938F13A11354A0475469E5  : public RuntimeObject
{
	X509ChainImpl_tBA1BF154DB9DC321EE068BBC53C7CF43CAA2621F* ___impl;
};
struct U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55  : public RuntimeObject
{
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	Il2CppChar ___m_value;
};
struct DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D 
{
	uint64_t ____dateData;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct MD5_t808E6AE387D5FCC368DBB86576572C1564D17E5A  : public HashAlgorithm_t299ECE61BBF4582B1F75734D43A96DDEC9B2004D
{
};
struct NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7  : public NameObjectCollectionBase_tB6400DF2FA3B64660D79586B79016B4A0BA645FC
{
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ____all;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ____allKeys;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct X509CertificateCollection_t2900D71D188EDCA7DEB5077D36103EE5DA6805CE  : public CollectionBase_t44F966CC555C87F2815D668FB4586526E1C2383F
{
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct X509Certificate_t966CC553AF25AE7991F5B4C2AACBCF6C66C8F9C4  : public RuntimeObject
{
	X509CertificateImpl_tF590E81705CE1FE152C590E5A875D4FE3BE348EF* ___impl;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___lazyCertHash;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___lazySerialNumber;
	String_t* ___lazyIssuer;
	String_t* ___lazySubject;
	String_t* ___lazyKeyAlgorithm;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___lazyKeyAlgorithmParameters;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___lazyPublicKey;
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___lazyNotBefore;
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___lazyNotAfter;
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D  : public MulticastDelegate_t
{
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859  : public MulticastDelegate_t
{
};
struct RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955  : public MulticastDelegate_t
{
};
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
};
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095_StaticFields
{
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___defaultEncoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___unicodeEncoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___bigEndianUnicode;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf7Encoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf8Encoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf32Encoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___asciiEncoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___latin1Encoding;
	Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54* ___encodings;
	RuntimeObject* ___s_InternalSyncObject;
};
struct HttpVersion_t2C7A10EB9472F5CBEE335426D23C90378989F10A_StaticFields
{
	Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7* ___Version10;
	Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7* ___Version11;
};
struct NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7_StaticFields
{
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ____noRoles;
};
struct Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_StaticFields
{
	Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* ___s_globalRandom;
};
struct Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_ThreadStaticFields
{
	Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* ___t_threadRandom;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_StaticFields
{
	U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55* ___U3CU3E9;
	Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D* ___U3CU3E9__40_0;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248  : public RuntimeArray
{
	ALIGN_FIELD (8) String_t* m_Items[1];

	inline String_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline String_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, String_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline String_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline String_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, String_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint8_t value)
	{
		m_Items[index] = value;
	}
};
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB  : public RuntimeArray
{
	ALIGN_FIELD (8) Il2CppChar m_Items[1];

	inline Il2CppChar GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Il2CppChar* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Il2CppChar value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Il2CppChar GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Il2CppChar* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Il2CppChar value)
	{
		m_Items[index] = value;
	}
};
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Func_2__ctor_m13C0A7F33154D861E2A041B52E88461832DA1697_gshared (Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Ext_Contains_TisRuntimeObject_m8E18B10E1457B495C20F9BFC00355CF312CE442A_gshared (RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_condition, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Version__ctor_m0871675040007535EA3D8083A4BEAE9DF8C92FF4 (Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7* __this, int32_t ___0_major, int32_t ___1_minor, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HttpHeaderInfo_get_IsMultiValueInRequest_mEBEFCE79102A977F2F4E02D455E6EDA0B926A1E6 (HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HttpHeaderInfo_get_IsMultiValueInResponse_mC9F52CEECDA3B9C8EB9C1207F427D2124F0611E0 (HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HttpHeaderInfo_get_IsRequest_m8F59F9AC3D9F89B535FDDA29037F43ECFBEFF6AE (HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HttpHeaderInfo_get_IsResponse_m555D94A706DCAC1FFF8E9B5FA9066F645735A617 (HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Random__ctor_m151183BD4F021499A98B9DE8502DAD4B12DD16AC (Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilder__ctor_m2619CA8D2C3476DF1A302D9D941498BB1C6164C5 (StringBuilder_t* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Byte_ToString_m793A41EEEB7B422F6FE658E99D2F7683F59EE310 (uint8_t* __this, String_t* ___0_format, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D (StringBuilder_t* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* String_Split_m3C63FA89A52BE352B4E49DB5379F7AAD6ACCA0E8 (String_t* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_separator, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_ToLower_m6191ABA3DC514ED47C10BDA23FD0DDCEAE7ACFBD (String_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1 (String_t* ___0_a, String_t* ___1_b, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* AuthenticationChallenge_ParseParameters_mBED353A7BFFA51B14FE76331BDD444266CE12730 (String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AuthenticationChallenge__ctor_m48DAF747A8B26E1530F2D31DF751EE7D6FB610CB (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* __this, int32_t ___0_scheme, NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* ___1_parameters, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NameValueCollection__ctor_mCA29E5386DACDF19F6F51BC395324F0A8EE05604 (NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Ext_SplitHeaderValue_m6550401BDE1B3A398A52816EAB8678D7E4FFD868 (String_t* ___0_value, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___1_separators, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t String_IndexOf_mE21E78F35EF4A7768E385A72814C88D22B689966 (String_t* __this, Il2CppChar ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE (String_t* __this, int32_t ___0_startIndex, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Trim_mCD6D8C6D4CFD15225D12DB7D3E0544CA80FB8DA5 (String_t* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Substring_m6BA4A3FA3800FE92662D0847CC8E1EEF940DF472 (String_t* __this, int32_t ___0_startIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Trim_m81BD35659E6F89DDD56816975E6E05390D023FE5 (String_t* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_trimChars, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F (NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* __this, String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8 (String_t* ___0_format, RuntimeObject* ___1_arg0, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_AppendFormat_m40962B9C5B41720C6424721E526C0D99D95112A2 (StringBuilder_t* __this, String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, RuntimeObject* ___3_arg2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_AppendFormat_mAB076D92DC92723B2224D75987BE463AF1CE7132 (StringBuilder_t* __this, String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_AppendFormat_mFA88863E4018C2912D1A783E0EA6DAE4F594124F (StringBuilder_t* __this, String_t* ___0_format, RuntimeObject* ___1_arg0, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationChallenge_ToBasicString_m5DB098D040616E91204ADBAB44C8D1E3AB902A45 (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationChallenge_ToDigestString_m3B11031DAAE0DCE6AC3A407CF2D1787BCD3A4A51 (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AuthenticationResponse__ctor_m8B754F23E79FBBCD8A1BD439E7CC9543F7237280 (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, int32_t ___0_scheme, NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* ___1_parameters, NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* ___2_credentials, uint32_t ___3_nonceCount, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t AuthenticationChallenge_get_Scheme_mED5DB27FE24F86C5637A5BF34554E24CC007B433 (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* AuthenticationChallenge_get_Parameters_mB74B31F3E5E3F332ADAF62D5B22D804C7805EF11 (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AuthenticationResponse__ctor_m2CACEA68603054505658053A88FC1FEC30F179D0 (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, int32_t ___0_scheme, NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* ___1_parameters, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* NetworkCredential_get_Username_m11E38EA63E08B905D21DEC62E064F6C5DFBCBE0F (NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NameValueCollection_set_Item_mEEC24334890E9C0A05B88638B6A65DF5D888B0B0 (NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* __this, String_t* ___0_name, String_t* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* NetworkCredential_get_Password_mC7EEA302483494AF51029D40BF3AD34974E149EC (NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* NetworkCredential_get_Domain_m94F479861014096C995BAFD486FDF1FCB7544BB6 (NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AuthenticationResponse_initAsDigest_mF1764BF15FCAD903AC6E134D8CBF333E8DD9319B (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mA0534D6E2AE4D67A6BD8D45B3321323930EB930C (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, RuntimeObject* ___3_arg2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_createA1_m0CDAB5F5A670DEDD5B42F6E5A20104090AC7EAC7 (String_t* ___0_username, String_t* ___1_password, String_t* ___2_realm, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_hash_m0678824675277D1E5BE17B591BC904438B65101E (String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MD5_t808E6AE387D5FCC368DBB86576572C1564D17E5A* MD5_Create_mD7AEBE7A752D163971C764A9A8CC0029C865F223 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* HashAlgorithm_ComputeHash_mC9CD24714D75A8D61F12509BF952A26347FF22FB (HashAlgorithm_t299ECE61BBF4582B1F75734D43A96DDEC9B2004D* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_buffer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* String_Split_m101D35FEC86371D2BB4E3480F6F896880093B2E9 (String_t* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_separator, const RuntimeMethod* method) ;
inline void Func_2__ctor_m247D5044A4E1F518CA84A38B9A9F30E66BDD8184 (Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D*, RuntimeObject*, intptr_t, const RuntimeMethod*))Func_2__ctor_m13C0A7F33154D861E2A041B52E88461832DA1697_gshared)(__this, ___0_object, ___1_method, method);
}
inline bool Ext_Contains_TisString_t_m21F17700FD2F34406CD7C4E4606CAF47F5D9CE17 (RuntimeObject* ___0_source, Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D* ___1_condition, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D*, const RuntimeMethod*))Ext_Contains_TisRuntimeObject_m8E18B10E1457B495C20F9BFC00355CF312CE442A_gshared)(___0_source, ___1_condition, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationChallenge_CreateNonceValue_mD99400D9BE382F60C645D8C6C17FE1B34BBE14BC (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_CreateRequestDigest_mF55FF510E22D3C634F08915B5253D27227E0266F (NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* ___0_parameters, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_createA1_mE47ADA8DD33D193F8656E6DF7FACAFDDF36FC37C (String_t* ___0_username, String_t* ___1_password, String_t* ___2_realm, String_t* ___3_nonce, String_t* ___4_cnonce, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_createA2_mA63C37736C690B00F5F9E4B6CDE2F9EDB5BF59BD (String_t* ___0_method, String_t* ___1_uri, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_createA2_m75EC602C7BA6964BA905202C6F0AA5B37B1080A0 (String_t* ___0_method, String_t* ___1_uri, String_t* ___2_entity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_m918500C1EFB475181349A79989BB79BB36102894 (String_t* ___0_format, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___1_args, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Convert_ToBase64String_mD0680EF77270244071965AFA1207921C73EEA323 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_inArray, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_AppendFormat_m14CB447291E6149BCF32E5E37DA21514BAD9C151 (StringBuilder_t* __this, String_t* ___0_format, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___1_args, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_ToBasicString_mF1E66F0E9ECBDCCD2AA2D2644E8DAB6154BF3753 (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_ToDigestString_m0FA5FA3FAEB1C8C2FE9E73424DE18C615CFF558F (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__ctor_m3455993C477A48D7DE97292F29F21BF3CCDDAB53 (U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, String_t* ___1_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LocalCertificateSelectionCallback__ctor_mE4F3A8BFF483881C2634112BB581CA4B07809805 (LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RemoteCertificateValidationCallback__ctor_mC5C0650D4E5D29475BDBDA5B43FEA44DB0DBF367 (RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HttpVersion__cctor_m11BC36FDEC9173A4C1127C65230ADB09EDD269C4 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HttpVersion_t2C7A10EB9472F5CBEE335426D23C90378989F10A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7* L_0 = (Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7*)il2cpp_codegen_object_new(Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7_il2cpp_TypeInfo_var);
		Version__ctor_m0871675040007535EA3D8083A4BEAE9DF8C92FF4(L_0, 1, 0, NULL);
		((HttpVersion_t2C7A10EB9472F5CBEE335426D23C90378989F10A_StaticFields*)il2cpp_codegen_static_fields_for(HttpVersion_t2C7A10EB9472F5CBEE335426D23C90378989F10A_il2cpp_TypeInfo_var))->___Version10 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((HttpVersion_t2C7A10EB9472F5CBEE335426D23C90378989F10A_StaticFields*)il2cpp_codegen_static_fields_for(HttpVersion_t2C7A10EB9472F5CBEE335426D23C90378989F10A_il2cpp_TypeInfo_var))->___Version10), (void*)L_0);
		Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7* L_1 = (Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7*)il2cpp_codegen_object_new(Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7_il2cpp_TypeInfo_var);
		Version__ctor_m0871675040007535EA3D8083A4BEAE9DF8C92FF4(L_1, 1, 1, NULL);
		((HttpVersion_t2C7A10EB9472F5CBEE335426D23C90378989F10A_StaticFields*)il2cpp_codegen_static_fields_for(HttpVersion_t2C7A10EB9472F5CBEE335426D23C90378989F10A_il2cpp_TypeInfo_var))->___Version11 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&((HttpVersion_t2C7A10EB9472F5CBEE335426D23C90378989F10A_StaticFields*)il2cpp_codegen_static_fields_for(HttpVersion_t2C7A10EB9472F5CBEE335426D23C90378989F10A_il2cpp_TypeInfo_var))->___Version11), (void*)L_1);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HttpHeaderInfo__ctor_m029BC1522F8128A87B729FCBFA879111383ABD37 (HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5* __this, String_t* ___0_headerName, int32_t ___1_headerType, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		String_t* L_0 = ___0_headerName;
		__this->____headerName = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____headerName), (void*)L_0);
		int32_t L_1 = ___1_headerType;
		__this->____headerType = L_1;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HttpHeaderInfo_get_IsMultiValueInRequest_mEBEFCE79102A977F2F4E02D455E6EDA0B926A1E6 (HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	bool V_1 = false;
	{
		int32_t L_0 = __this->____headerType;
		V_0 = ((int32_t)((int32_t)L_0&((int32_t)16)));
		int32_t L_1 = V_0;
		V_1 = (bool)((((int32_t)L_1) == ((int32_t)((int32_t)16)))? 1 : 0);
		goto IL_0013;
	}

IL_0013:
	{
		bool L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HttpHeaderInfo_get_IsMultiValueInResponse_mC9F52CEECDA3B9C8EB9C1207F427D2124F0611E0 (HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	bool V_1 = false;
	{
		int32_t L_0 = __this->____headerType;
		V_0 = ((int32_t)((int32_t)L_0&((int32_t)32)));
		int32_t L_1 = V_0;
		V_1 = (bool)((((int32_t)L_1) == ((int32_t)((int32_t)32)))? 1 : 0);
		goto IL_0013;
	}

IL_0013:
	{
		bool L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* HttpHeaderInfo_get_HeaderName_mBD39E62A4C8C41DD7A75B4A7CE5162095C600B89 (HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5* __this, const RuntimeMethod* method) 
{
	String_t* V_0 = NULL;
	{
		String_t* L_0 = __this->____headerName;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		String_t* L_1 = V_0;
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HttpHeaderInfo_get_IsRequest_m8F59F9AC3D9F89B535FDDA29037F43ECFBEFF6AE (HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	bool V_1 = false;
	{
		int32_t L_0 = __this->____headerType;
		V_0 = ((int32_t)((int32_t)L_0&1));
		int32_t L_1 = V_0;
		V_1 = (bool)((((int32_t)L_1) == ((int32_t)1))? 1 : 0);
		goto IL_0011;
	}

IL_0011:
	{
		bool L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HttpHeaderInfo_get_IsResponse_m555D94A706DCAC1FFF8E9B5FA9066F645735A617 (HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	bool V_1 = false;
	{
		int32_t L_0 = __this->____headerType;
		V_0 = ((int32_t)((int32_t)L_0&2));
		int32_t L_1 = V_0;
		V_1 = (bool)((((int32_t)L_1) == ((int32_t)2))? 1 : 0);
		goto IL_0011;
	}

IL_0011:
	{
		bool L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HttpHeaderInfo_IsMultiValue_m48F09D53D36D229FEC7EC4DD584D2EAF43E58B85 (HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5* __this, bool ___0_response, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	bool V_1 = false;
	bool V_2 = false;
	bool G_B4_0 = false;
	bool G_B8_0 = false;
	{
		int32_t L_0 = __this->____headerType;
		V_0 = ((int32_t)((int32_t)L_0&8));
		int32_t L_1 = V_0;
		V_1 = (bool)((((int32_t)((((int32_t)L_1) == ((int32_t)8))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_0029;
		}
	}
	{
		bool L_3 = ___0_response;
		if (L_3)
		{
			goto IL_0020;
		}
	}
	{
		bool L_4;
		L_4 = HttpHeaderInfo_get_IsMultiValueInRequest_mEBEFCE79102A977F2F4E02D455E6EDA0B926A1E6(__this, NULL);
		G_B4_0 = L_4;
		goto IL_0026;
	}

IL_0020:
	{
		bool L_5;
		L_5 = HttpHeaderInfo_get_IsMultiValueInResponse_mC9F52CEECDA3B9C8EB9C1207F427D2124F0611E0(__this, NULL);
		G_B4_0 = L_5;
	}

IL_0026:
	{
		V_2 = G_B4_0;
		goto IL_003d;
	}

IL_0029:
	{
		bool L_6 = ___0_response;
		if (L_6)
		{
			goto IL_0034;
		}
	}
	{
		bool L_7;
		L_7 = HttpHeaderInfo_get_IsRequest_m8F59F9AC3D9F89B535FDDA29037F43ECFBEFF6AE(__this, NULL);
		G_B8_0 = L_7;
		goto IL_003a;
	}

IL_0034:
	{
		bool L_8;
		L_8 = HttpHeaderInfo_get_IsResponse_m555D94A706DCAC1FFF8E9B5FA9066F645735A617(__this, NULL);
		G_B8_0 = L_8;
	}

IL_003a:
	{
		V_2 = G_B8_0;
		goto IL_003d;
	}

IL_003d:
	{
		bool L_9 = V_2;
		return L_9;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HttpHeaderInfo_IsRestricted_mB2D9FB989CF4520F515E67F68CDB4D853CF4A81D (HttpHeaderInfo_tA73176CBC751DD4D61D99EC93671348F52EF6DE5* __this, bool ___0_response, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	bool V_1 = false;
	bool V_2 = false;
	bool G_B5_0 = false;
	{
		int32_t L_0 = __this->____headerType;
		V_0 = ((int32_t)((int32_t)L_0&4));
		int32_t L_1 = V_0;
		V_1 = (bool)((((int32_t)((((int32_t)L_1) == ((int32_t)4))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_0019;
		}
	}
	{
		V_2 = (bool)0;
		goto IL_002d;
	}

IL_0019:
	{
		bool L_3 = ___0_response;
		if (L_3)
		{
			goto IL_0024;
		}
	}
	{
		bool L_4;
		L_4 = HttpHeaderInfo_get_IsRequest_m8F59F9AC3D9F89B535FDDA29037F43ECFBEFF6AE(__this, NULL);
		G_B5_0 = L_4;
		goto IL_002a;
	}

IL_0024:
	{
		bool L_5;
		L_5 = HttpHeaderInfo_get_IsResponse_m555D94A706DCAC1FFF8E9B5FA9066F645735A617(__this, NULL);
		G_B5_0 = L_5;
	}

IL_002a:
	{
		V_2 = G_B5_0;
		goto IL_002d;
	}

IL_002d:
	{
		bool L_6 = V_2;
		return L_6;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetworkCredential__cctor_m6A48BD24A0C90FEFC3A8CDAFF096994F0AA50B6E (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)0);
		((NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7_StaticFields*)il2cpp_codegen_static_fields_for(NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7_il2cpp_TypeInfo_var))->____noRoles = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7_StaticFields*)il2cpp_codegen_static_fields_for(NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7_il2cpp_TypeInfo_var))->____noRoles), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* NetworkCredential_get_Domain_m94F479861014096C995BAFD486FDF1FCB7544BB6 (NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	String_t* G_B2_0 = NULL;
	String_t* G_B1_0 = NULL;
	{
		String_t* L_0 = __this->____domain;
		String_t* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_0010;
		}
		G_B1_0 = L_1;
	}
	{
		String_t* L_2 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty;
		G_B2_0 = L_2;
	}

IL_0010:
	{
		V_0 = G_B2_0;
		goto IL_0013;
	}

IL_0013:
	{
		String_t* L_3 = V_0;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* NetworkCredential_get_Password_mC7EEA302483494AF51029D40BF3AD34974E149EC (NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	String_t* G_B2_0 = NULL;
	String_t* G_B1_0 = NULL;
	{
		String_t* L_0 = __this->____password;
		String_t* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_0010;
		}
		G_B1_0 = L_1;
	}
	{
		String_t* L_2 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty;
		G_B2_0 = L_2;
	}

IL_0010:
	{
		V_0 = G_B2_0;
		goto IL_0013;
	}

IL_0013:
	{
		String_t* L_3 = V_0;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* NetworkCredential_get_Username_m11E38EA63E08B905D21DEC62E064F6C5DFBCBE0F (NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* __this, const RuntimeMethod* method) 
{
	String_t* V_0 = NULL;
	{
		String_t* L_0 = __this->____username;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		String_t* L_1 = V_0;
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AuthenticationChallenge__ctor_m48DAF747A8B26E1530F2D31DF751EE7D6FB610CB (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* __this, int32_t ___0_scheme, NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* ___1_parameters, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_scheme;
		__this->____scheme = L_0;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_1 = ___1_parameters;
		__this->____parameters = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____parameters), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* AuthenticationChallenge_get_Parameters_mB74B31F3E5E3F332ADAF62D5B22D804C7805EF11 (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* __this, const RuntimeMethod* method) 
{
	NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* V_0 = NULL;
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_0 = __this->____parameters;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_1 = V_0;
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t AuthenticationChallenge_get_Scheme_mED5DB27FE24F86C5637A5BF34554E24CC007B433 (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____scheme;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		int32_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationChallenge_CreateNonceValue_mD99400D9BE382F60C645D8C6C17FE1B34BBE14BC (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral65A0F9B64ACE7C859A284EA54B1190CBF83E1260);
		s_Il2CppMethodInitialized = true;
	}
	Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* V_0 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_1 = NULL;
	StringBuilder_t* V_2 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_3 = NULL;
	int32_t V_4 = 0;
	uint8_t V_5 = 0x0;
	String_t* V_6 = NULL;
	{
		Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* L_0 = (Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8*)il2cpp_codegen_object_new(Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8_il2cpp_TypeInfo_var);
		Random__ctor_m151183BD4F021499A98B9DE8502DAD4B12DD16AC(L_0, NULL);
		V_0 = L_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)16));
		V_1 = L_1;
		Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* L_2 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = V_1;
		NullCheck(L_2);
		VirtualActionInvoker1< ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* >::Invoke(8, L_2, L_3);
		StringBuilder_t* L_4 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m2619CA8D2C3476DF1A302D9D941498BB1C6164C5(L_4, ((int32_t)32), NULL);
		V_2 = L_4;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_1;
		V_3 = L_5;
		V_4 = 0;
		goto IL_0046;
	}

IL_0027:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = V_3;
		int32_t L_7 = V_4;
		NullCheck(L_6);
		int32_t L_8 = L_7;
		uint8_t L_9 = (L_6)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		V_5 = L_9;
		StringBuilder_t* L_10 = V_2;
		String_t* L_11;
		L_11 = Byte_ToString_m793A41EEEB7B422F6FE658E99D2F7683F59EE310((&V_5), _stringLiteral65A0F9B64ACE7C859A284EA54B1190CBF83E1260, NULL);
		NullCheck(L_10);
		StringBuilder_t* L_12;
		L_12 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_10, L_11, NULL);
		int32_t L_13 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0046:
	{
		int32_t L_14 = V_4;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_15 = V_3;
		NullCheck(L_15);
		if ((((int32_t)L_14) < ((int32_t)((int32_t)(((RuntimeArray*)L_15)->max_length)))))
		{
			goto IL_0027;
		}
	}
	{
		StringBuilder_t* L_16 = V_2;
		NullCheck(L_16);
		String_t* L_17;
		L_17 = VirtualFuncInvoker0< String_t* >::Invoke(3, L_16);
		V_6 = L_17;
		goto IL_0057;
	}

IL_0057:
	{
		String_t* L_18 = V_6;
		return L_18;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* AuthenticationChallenge_Parse_mEE43C5FC70E11A70E65B84FD8407ABD65FB380A6 (String_t* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6E34E505E342A11AE48ECA3D71434F8043A88EB6);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC60811AD65D0557EF69DFB2F66D9621903D5B62A);
		s_Il2CppMethodInitialized = true;
	}
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* V_0 = NULL;
	String_t* V_1 = NULL;
	bool V_2 = false;
	AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* V_3 = NULL;
	bool V_4 = false;
	NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* V_5 = NULL;
	bool V_6 = false;
	NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* V_7 = NULL;
	{
		String_t* L_0 = ___0_value;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_1 = (CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)SZArrayNew(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB_il2cpp_TypeInfo_var, (uint32_t)1);
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_2 = L_1;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(0), (Il2CppChar)((int32_t)32));
		NullCheck(L_0);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_3;
		L_3 = String_Split_m3C63FA89A52BE352B4E49DB5379F7AAD6ACCA0E8(L_0, L_2, 2, NULL);
		V_0 = L_3;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_4 = V_0;
		NullCheck(L_4);
		V_2 = (bool)((((int32_t)((((int32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))) == ((int32_t)2))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_5 = V_2;
		if (!L_5)
		{
			goto IL_0025;
		}
	}
	{
		V_3 = (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2*)NULL;
		goto IL_0080;
	}

IL_0025:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_6 = V_0;
		NullCheck(L_6);
		int32_t L_7 = 0;
		String_t* L_8 = (L_6)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		NullCheck(L_8);
		String_t* L_9;
		L_9 = String_ToLower_m6191ABA3DC514ED47C10BDA23FD0DDCEAE7ACFBD(L_8, NULL);
		V_1 = L_9;
		String_t* L_10 = V_1;
		bool L_11;
		L_11 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_10, _stringLiteral6E34E505E342A11AE48ECA3D71434F8043A88EB6, NULL);
		V_4 = L_11;
		bool L_12 = V_4;
		if (!L_12)
		{
			goto IL_0055;
		}
	}
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_13 = V_0;
		NullCheck(L_13);
		int32_t L_14 = 1;
		String_t* L_15 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_16;
		L_16 = AuthenticationChallenge_ParseParameters_mBED353A7BFFA51B14FE76331BDD444266CE12730(L_15, NULL);
		V_5 = L_16;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_17 = V_5;
		AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* L_18 = (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2*)il2cpp_codegen_object_new(AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2_il2cpp_TypeInfo_var);
		AuthenticationChallenge__ctor_m48DAF747A8B26E1530F2D31DF751EE7D6FB610CB(L_18, 8, L_17, NULL);
		V_3 = L_18;
		goto IL_0080;
	}

IL_0055:
	{
		String_t* L_19 = V_1;
		bool L_20;
		L_20 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_19, _stringLiteralC60811AD65D0557EF69DFB2F66D9621903D5B62A, NULL);
		V_6 = L_20;
		bool L_21 = V_6;
		if (!L_21)
		{
			goto IL_007c;
		}
	}
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_22 = V_0;
		NullCheck(L_22);
		int32_t L_23 = 1;
		String_t* L_24 = (L_22)->GetAt(static_cast<il2cpp_array_size_t>(L_23));
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_25;
		L_25 = AuthenticationChallenge_ParseParameters_mBED353A7BFFA51B14FE76331BDD444266CE12730(L_24, NULL);
		V_7 = L_25;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_26 = V_7;
		AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* L_27 = (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2*)il2cpp_codegen_object_new(AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2_il2cpp_TypeInfo_var);
		AuthenticationChallenge__ctor_m48DAF747A8B26E1530F2D31DF751EE7D6FB610CB(L_27, 1, L_26, NULL);
		V_3 = L_27;
		goto IL_0080;
	}

IL_007c:
	{
		V_3 = (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2*)NULL;
		goto IL_0080;
	}

IL_0080:
	{
		AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* L_28 = V_3;
		return L_28;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* AuthenticationChallenge_ParseParameters_mBED353A7BFFA51B14FE76331BDD444266CE12730 (String_t* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Ext_t6D7C499436D2B147B941E873C73C930E159B53D0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_1_t349E66EC5F09B881A8E52EE40A1AB9EC60E08E44_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_1_t73FD060C436E3C4264A734C8F8DCC01DFF6046B8_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	String_t* V_2 = NULL;
	int32_t V_3 = 0;
	String_t* V_4 = NULL;
	String_t* V_5 = NULL;
	NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* V_6 = NULL;
	String_t* G_B5_0 = NULL;
	String_t* G_B9_0 = NULL;
	String_t* G_B11_0 = NULL;
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_0 = (NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7*)il2cpp_codegen_object_new(NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7_il2cpp_TypeInfo_var);
		NameValueCollection__ctor_mCA29E5386DACDF19F6F51BC395324F0A8EE05604(L_0, NULL);
		V_0 = L_0;
		String_t* L_1 = ___0_value;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_2 = (CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)SZArrayNew(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB_il2cpp_TypeInfo_var, (uint32_t)1);
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_3 = L_2;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(0), (Il2CppChar)((int32_t)44));
		il2cpp_codegen_runtime_class_init_inline(Ext_t6D7C499436D2B147B941E873C73C930E159B53D0_il2cpp_TypeInfo_var);
		RuntimeObject* L_4;
		L_4 = Ext_SplitHeaderValue_m6550401BDE1B3A398A52816EAB8678D7E4FFD868(L_1, L_3, NULL);
		NullCheck(L_4);
		RuntimeObject* L_5;
		L_5 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerable_1_t349E66EC5F09B881A8E52EE40A1AB9EC60E08E44_il2cpp_TypeInfo_var, L_4);
		V_1 = L_5;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00b2:
			{
				{
					RuntimeObject* L_6 = V_1;
					if (!L_6)
					{
						goto IL_00bc;
					}
				}
				{
					RuntimeObject* L_7 = V_1;
					NullCheck(L_7);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_7);
				}

IL_00bc:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00a5_1;
			}

IL_0024_1:
			{
				RuntimeObject* L_8 = V_1;
				NullCheck(L_8);
				String_t* L_9;
				L_9 = InterfaceFuncInvoker0< String_t* >::Invoke(0, IEnumerator_1_t73FD060C436E3C4264A734C8F8DCC01DFF6046B8_il2cpp_TypeInfo_var, L_8);
				V_2 = L_9;
				String_t* L_10 = V_2;
				NullCheck(L_10);
				int32_t L_11;
				L_11 = String_IndexOf_mE21E78F35EF4A7768E385A72814C88D22B689966(L_10, ((int32_t)61), NULL);
				V_3 = L_11;
				int32_t L_12 = V_3;
				if ((((int32_t)L_12) > ((int32_t)0)))
				{
					goto IL_003c_1;
				}
			}
			{
				G_B5_0 = ((String_t*)(NULL));
				goto IL_0049_1;
			}

IL_003c_1:
			{
				String_t* L_13 = V_2;
				int32_t L_14 = V_3;
				NullCheck(L_13);
				String_t* L_15;
				L_15 = String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE(L_13, 0, L_14, NULL);
				NullCheck(L_15);
				String_t* L_16;
				L_16 = String_Trim_mCD6D8C6D4CFD15225D12DB7D3E0544CA80FB8DA5(L_15, NULL);
				G_B5_0 = L_16;
			}

IL_0049_1:
			{
				V_4 = G_B5_0;
				int32_t L_17 = V_3;
				if ((((int32_t)L_17) < ((int32_t)0)))
				{
					goto IL_0081_1;
				}
			}
			{
				int32_t L_18 = V_3;
				String_t* L_19 = V_2;
				NullCheck(L_19);
				int32_t L_20;
				L_20 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_19, NULL);
				if ((((int32_t)L_18) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_20, 1)))))
				{
					goto IL_0061_1;
				}
			}
			{
				String_t* L_21 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty;
				G_B9_0 = L_21;
				goto IL_007f_1;
			}

IL_0061_1:
			{
				String_t* L_22 = V_2;
				int32_t L_23 = V_3;
				NullCheck(L_22);
				String_t* L_24;
				L_24 = String_Substring_m6BA4A3FA3800FE92662D0847CC8E1EEF940DF472(L_22, ((int32_t)il2cpp_codegen_add(L_23, 1)), NULL);
				NullCheck(L_24);
				String_t* L_25;
				L_25 = String_Trim_mCD6D8C6D4CFD15225D12DB7D3E0544CA80FB8DA5(L_24, NULL);
				CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_26 = (CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)SZArrayNew(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB_il2cpp_TypeInfo_var, (uint32_t)1);
				CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_27 = L_26;
				NullCheck(L_27);
				(L_27)->SetAt(static_cast<il2cpp_array_size_t>(0), (Il2CppChar)((int32_t)34));
				NullCheck(L_25);
				String_t* L_28;
				L_28 = String_Trim_m81BD35659E6F89DDD56816975E6E05390D023FE5(L_25, L_27, NULL);
				G_B9_0 = L_28;
			}

IL_007f_1:
			{
				G_B11_0 = G_B9_0;
				goto IL_0097_1;
			}

IL_0081_1:
			{
				String_t* L_29 = V_2;
				NullCheck(L_29);
				String_t* L_30;
				L_30 = String_Trim_mCD6D8C6D4CFD15225D12DB7D3E0544CA80FB8DA5(L_29, NULL);
				CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_31 = (CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)SZArrayNew(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB_il2cpp_TypeInfo_var, (uint32_t)1);
				CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_32 = L_31;
				NullCheck(L_32);
				(L_32)->SetAt(static_cast<il2cpp_array_size_t>(0), (Il2CppChar)((int32_t)34));
				NullCheck(L_30);
				String_t* L_33;
				L_33 = String_Trim_m81BD35659E6F89DDD56816975E6E05390D023FE5(L_30, L_32, NULL);
				G_B11_0 = L_33;
			}

IL_0097_1:
			{
				V_5 = G_B11_0;
				NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_34 = V_0;
				String_t* L_35 = V_4;
				String_t* L_36 = V_5;
				NullCheck(L_34);
				VirtualActionInvoker2< String_t*, String_t* >::Invoke(14, L_34, L_35, L_36);
			}

IL_00a5_1:
			{
				RuntimeObject* L_37 = V_1;
				NullCheck(L_37);
				bool L_38;
				L_38 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_37);
				if (L_38)
				{
					goto IL_0024_1;
				}
			}
			{
				goto IL_00bd;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00bd:
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_39 = V_0;
		V_6 = L_39;
		goto IL_00c2;
	}

IL_00c2:
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_40 = V_6;
		return L_40;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationChallenge_ToBasicString_m5DB098D040616E91204ADBAB44C8D1E3AB902A45 (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0B9F5C4167997CA1C1F9659AB0228EEB594BA8C3);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7D1CAF9B55BE135BC8B1C459D2052FBCF135556);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_0 = __this->____parameters;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_0, _stringLiteralB7D1CAF9B55BE135BC8B1C459D2052FBCF135556, NULL);
		String_t* L_2;
		L_2 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(_stringLiteral0B9F5C4167997CA1C1F9659AB0228EEB594BA8C3, L_1, NULL);
		V_0 = L_2;
		goto IL_001e;
	}

IL_001e:
	{
		String_t* L_3 = V_0;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationChallenge_ToDigestString_m3B11031DAAE0DCE6AC3A407CF2D1787BCD3A4A51 (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral11E42B7A5E1CF74E4375D71D8CE94F3D8D446DBA);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral23786080E9FF3ED506C54C7BC75ED560F8E0D17A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2555543242A278889EA1F704BD696770579E9304);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral56527A2300BB0A611AE7B1418C0BFCB781C48103);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral59A9856ADD5A93479660B0DADE65D1636B473A27);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral59EF9AD20EC836CD3EF188D82C03E21009DB374B);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9C35BA15FC8288F6F7A229DD42F48D4FB70DCC2E);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA33AC456085EAEABCEC676232468748A49977DBE);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA9AF8D13B64E63A31A01386E007E5C9CF3A6CF5B);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB452E2B6A53FE9D2E35664FB7EB8D18D4773223C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7D1CAF9B55BE135BC8B1C459D2052FBCF135556);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE36C77CFC3454AF8169617B02C29C26EE456DBCD);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE806CD6CD3D351202351C73AC5A552506A239F67);
		s_Il2CppMethodInitialized = true;
	}
	StringBuilder_t* V_0 = NULL;
	String_t* V_1 = NULL;
	String_t* V_2 = NULL;
	String_t* V_3 = NULL;
	String_t* V_4 = NULL;
	String_t* V_5 = NULL;
	String_t* V_6 = NULL;
	String_t* V_7 = NULL;
	bool V_8 = false;
	bool V_9 = false;
	bool V_10 = false;
	bool V_11 = false;
	bool V_12 = false;
	String_t* V_13 = NULL;
	{
		StringBuilder_t* L_0 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m2619CA8D2C3476DF1A302D9D941498BB1C6164C5(L_0, ((int32_t)128), NULL);
		V_0 = L_0;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_1 = __this->____parameters;
		NullCheck(L_1);
		String_t* L_2;
		L_2 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_1, _stringLiteral11E42B7A5E1CF74E4375D71D8CE94F3D8D446DBA, NULL);
		V_1 = L_2;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_3 = __this->____parameters;
		NullCheck(L_3);
		String_t* L_4;
		L_4 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_3, _stringLiteralB7D1CAF9B55BE135BC8B1C459D2052FBCF135556, NULL);
		V_2 = L_4;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_5 = __this->____parameters;
		NullCheck(L_5);
		String_t* L_6;
		L_6 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_5, _stringLiteral2555543242A278889EA1F704BD696770579E9304, NULL);
		V_3 = L_6;
		String_t* L_7 = V_1;
		V_8 = (bool)((!(((RuntimeObject*)(String_t*)L_7) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_8 = V_8;
		if (!L_8)
		{
			goto IL_005c;
		}
	}
	{
		StringBuilder_t* L_9 = V_0;
		String_t* L_10 = V_2;
		String_t* L_11 = V_1;
		String_t* L_12 = V_3;
		NullCheck(L_9);
		StringBuilder_t* L_13;
		L_13 = StringBuilder_AppendFormat_m40962B9C5B41720C6424721E526C0D99D95112A2(L_9, _stringLiteralB452E2B6A53FE9D2E35664FB7EB8D18D4773223C, L_10, L_11, L_12, NULL);
		goto IL_006c;
	}

IL_005c:
	{
		StringBuilder_t* L_14 = V_0;
		String_t* L_15 = V_2;
		String_t* L_16 = V_3;
		NullCheck(L_14);
		StringBuilder_t* L_17;
		L_17 = StringBuilder_AppendFormat_mAB076D92DC92723B2224D75987BE463AF1CE7132(L_14, _stringLiteral23786080E9FF3ED506C54C7BC75ED560F8E0D17A, L_15, L_16, NULL);
	}

IL_006c:
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_18 = __this->____parameters;
		NullCheck(L_18);
		String_t* L_19;
		L_19 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_18, _stringLiteral9C35BA15FC8288F6F7A229DD42F48D4FB70DCC2E, NULL);
		V_4 = L_19;
		String_t* L_20 = V_4;
		V_9 = (bool)((!(((RuntimeObject*)(String_t*)L_20) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_21 = V_9;
		if (!L_21)
		{
			goto IL_0097;
		}
	}
	{
		StringBuilder_t* L_22 = V_0;
		String_t* L_23 = V_4;
		NullCheck(L_22);
		StringBuilder_t* L_24;
		L_24 = StringBuilder_AppendFormat_mFA88863E4018C2912D1A783E0EA6DAE4F594124F(L_22, _stringLiteral59A9856ADD5A93479660B0DADE65D1636B473A27, L_23, NULL);
	}

IL_0097:
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_25 = __this->____parameters;
		NullCheck(L_25);
		String_t* L_26;
		L_26 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_25, _stringLiteral59EF9AD20EC836CD3EF188D82C03E21009DB374B, NULL);
		V_5 = L_26;
		String_t* L_27 = V_5;
		V_10 = (bool)((!(((RuntimeObject*)(String_t*)L_27) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_28 = V_10;
		if (!L_28)
		{
			goto IL_00c2;
		}
	}
	{
		StringBuilder_t* L_29 = V_0;
		String_t* L_30 = V_5;
		NullCheck(L_29);
		StringBuilder_t* L_31;
		L_31 = StringBuilder_AppendFormat_mFA88863E4018C2912D1A783E0EA6DAE4F594124F(L_29, _stringLiteralA33AC456085EAEABCEC676232468748A49977DBE, L_30, NULL);
	}

IL_00c2:
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_32 = __this->____parameters;
		NullCheck(L_32);
		String_t* L_33;
		L_33 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_32, _stringLiteralA9AF8D13B64E63A31A01386E007E5C9CF3A6CF5B, NULL);
		V_6 = L_33;
		String_t* L_34 = V_6;
		V_11 = (bool)((!(((RuntimeObject*)(String_t*)L_34) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_35 = V_11;
		if (!L_35)
		{
			goto IL_00ed;
		}
	}
	{
		StringBuilder_t* L_36 = V_0;
		String_t* L_37 = V_6;
		NullCheck(L_36);
		StringBuilder_t* L_38;
		L_38 = StringBuilder_AppendFormat_mFA88863E4018C2912D1A783E0EA6DAE4F594124F(L_36, _stringLiteralE806CD6CD3D351202351C73AC5A552506A239F67, L_37, NULL);
	}

IL_00ed:
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_39 = __this->____parameters;
		NullCheck(L_39);
		String_t* L_40;
		L_40 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_39, _stringLiteral56527A2300BB0A611AE7B1418C0BFCB781C48103, NULL);
		V_7 = L_40;
		String_t* L_41 = V_7;
		V_12 = (bool)((!(((RuntimeObject*)(String_t*)L_41) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_42 = V_12;
		if (!L_42)
		{
			goto IL_0118;
		}
	}
	{
		StringBuilder_t* L_43 = V_0;
		String_t* L_44 = V_7;
		NullCheck(L_43);
		StringBuilder_t* L_45;
		L_45 = StringBuilder_AppendFormat_mFA88863E4018C2912D1A783E0EA6DAE4F594124F(L_43, _stringLiteralE36C77CFC3454AF8169617B02C29C26EE456DBCD, L_44, NULL);
	}

IL_0118:
	{
		StringBuilder_t* L_46 = V_0;
		NullCheck(L_46);
		String_t* L_47;
		L_47 = VirtualFuncInvoker0< String_t* >::Invoke(3, L_46);
		V_13 = L_47;
		goto IL_0122;
	}

IL_0122:
	{
		String_t* L_48 = V_13;
		return L_48;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationChallenge_ToString_m9868230E069322C70AA2C028950C2A38F4D42DC6 (AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	String_t* V_1 = NULL;
	bool V_2 = false;
	{
		int32_t L_0 = __this->____scheme;
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)8))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0017;
		}
	}
	{
		String_t* L_2;
		L_2 = AuthenticationChallenge_ToBasicString_m5DB098D040616E91204ADBAB44C8D1E3AB902A45(__this, NULL);
		V_1 = L_2;
		goto IL_0035;
	}

IL_0017:
	{
		int32_t L_3 = __this->____scheme;
		V_2 = (bool)((((int32_t)L_3) == ((int32_t)1))? 1 : 0);
		bool L_4 = V_2;
		if (!L_4)
		{
			goto IL_002d;
		}
	}
	{
		String_t* L_5;
		L_5 = AuthenticationChallenge_ToDigestString_m3B11031DAAE0DCE6AC3A407CF2D1787BCD3A4A51(__this, NULL);
		V_1 = L_5;
		goto IL_0035;
	}

IL_002d:
	{
		String_t* L_6 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty;
		V_1 = L_6;
		goto IL_0035;
	}

IL_0035:
	{
		String_t* L_7 = V_1;
		return L_7;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AuthenticationResponse__ctor_m2CACEA68603054505658053A88FC1FEC30F179D0 (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, int32_t ___0_scheme, NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* ___1_parameters, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_scheme;
		__this->____scheme = L_0;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_1 = ___1_parameters;
		__this->____parameters = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____parameters), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AuthenticationResponse__ctor_mF4EFC52E66C4C03E06324C983AF53D04BA8641F6 (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* ___0_credentials, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_0 = (NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7*)il2cpp_codegen_object_new(NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7_il2cpp_TypeInfo_var);
		NameValueCollection__ctor_mCA29E5386DACDF19F6F51BC395324F0A8EE05604(L_0, NULL);
		NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* L_1 = ___0_credentials;
		AuthenticationResponse__ctor_m8B754F23E79FBBCD8A1BD439E7CC9543F7237280(__this, 8, L_0, L_1, 0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AuthenticationResponse__ctor_m2C2D07F49CB1EBBB6C30F0A97E970993064F9551 (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* ___0_challenge, NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* ___1_credentials, uint32_t ___2_nonceCount, const RuntimeMethod* method) 
{
	{
		AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* L_0 = ___0_challenge;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = AuthenticationChallenge_get_Scheme_mED5DB27FE24F86C5637A5BF34554E24CC007B433(L_0, NULL);
		AuthenticationChallenge_t6EADF65CD74974F1783AD785778A24AA7F6D00A2* L_2 = ___0_challenge;
		NullCheck(L_2);
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_3;
		L_3 = AuthenticationChallenge_get_Parameters_mB74B31F3E5E3F332ADAF62D5B22D804C7805EF11(L_2, NULL);
		NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* L_4 = ___1_credentials;
		uint32_t L_5 = ___2_nonceCount;
		AuthenticationResponse__ctor_m8B754F23E79FBBCD8A1BD439E7CC9543F7237280(__this, L_1, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AuthenticationResponse__ctor_m8B754F23E79FBBCD8A1BD439E7CC9543F7237280 (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, int32_t ___0_scheme, NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* ___1_parameters, NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* ___2_credentials, uint32_t ___3_nonceCount, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral10C63C8C602DD5E38BE4A758C90EBAC324CD3E69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE3A56BE62F0FB42D8062A17A4957C2142D815735);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE8F97FBA9104D1EA5047948E6DFB67FACD9F5B73);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		int32_t L_0 = ___0_scheme;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_1 = ___1_parameters;
		AuthenticationResponse__ctor_m2CACEA68603054505658053A88FC1FEC30F179D0(__this, L_0, L_1, NULL);
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_2 = __this->____parameters;
		NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* L_3 = ___2_credentials;
		NullCheck(L_3);
		String_t* L_4;
		L_4 = NetworkCredential_get_Username_m11E38EA63E08B905D21DEC62E064F6C5DFBCBE0F(L_3, NULL);
		NullCheck(L_2);
		NameValueCollection_set_Item_mEEC24334890E9C0A05B88638B6A65DF5D888B0B0(L_2, _stringLiteralE3A56BE62F0FB42D8062A17A4957C2142D815735, L_4, NULL);
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_5 = __this->____parameters;
		NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* L_6 = ___2_credentials;
		NullCheck(L_6);
		String_t* L_7;
		L_7 = NetworkCredential_get_Password_mC7EEA302483494AF51029D40BF3AD34974E149EC(L_6, NULL);
		NullCheck(L_5);
		NameValueCollection_set_Item_mEEC24334890E9C0A05B88638B6A65DF5D888B0B0(L_5, _stringLiteralE8F97FBA9104D1EA5047948E6DFB67FACD9F5B73, L_7, NULL);
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_8 = __this->____parameters;
		NetworkCredential_tAF63174AAA7DA3BECD41DCE272F38FC13984DFF7* L_9 = ___2_credentials;
		NullCheck(L_9);
		String_t* L_10;
		L_10 = NetworkCredential_get_Domain_m94F479861014096C995BAFD486FDF1FCB7544BB6(L_9, NULL);
		NullCheck(L_8);
		NameValueCollection_set_Item_mEEC24334890E9C0A05B88638B6A65DF5D888B0B0(L_8, _stringLiteral10C63C8C602DD5E38BE4A758C90EBAC324CD3E69, L_10, NULL);
		uint32_t L_11 = ___3_nonceCount;
		__this->____nonceCount = L_11;
		int32_t L_12 = ___0_scheme;
		V_0 = (bool)((((int32_t)L_12) == ((int32_t)1))? 1 : 0);
		bool L_13 = V_0;
		if (!L_13)
		{
			goto IL_0066;
		}
	}
	{
		AuthenticationResponse_initAsDigest_mF1764BF15FCAD903AC6E134D8CBF333E8DD9319B(__this, NULL);
	}

IL_0066:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t AuthenticationResponse_get_NonceCount_m1B1F72365B45F62ED7D244C56A1E2B38063514EB (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	uint32_t G_B3_0 = 0;
	{
		uint32_t L_0 = __this->____nonceCount;
		if ((!(((uint32_t)L_0) >= ((uint32_t)(-1)))))
		{
			goto IL_000d;
		}
	}
	{
		G_B3_0 = ((uint32_t)(0));
		goto IL_0013;
	}

IL_000d:
	{
		uint32_t L_1 = __this->____nonceCount;
		G_B3_0 = L_1;
	}

IL_0013:
	{
		V_0 = G_B3_0;
		goto IL_0016;
	}

IL_0016:
	{
		uint32_t L_2 = V_0;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_createA1_m0CDAB5F5A670DEDD5B42F6E5A20104090AC7EAC7 (String_t* ___0_username, String_t* ___1_password, String_t* ___2_realm, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral17490F55601C1F90A7803263837FE3F21E759D69);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		String_t* L_0 = ___0_username;
		String_t* L_1 = ___2_realm;
		String_t* L_2 = ___1_password;
		String_t* L_3;
		L_3 = String_Format_mA0534D6E2AE4D67A6BD8D45B3321323930EB930C(_stringLiteral17490F55601C1F90A7803263837FE3F21E759D69, L_0, L_1, L_2, NULL);
		V_0 = L_3;
		goto IL_0011;
	}

IL_0011:
	{
		String_t* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_createA1_mE47ADA8DD33D193F8656E6DF7FACAFDDF36FC37C (String_t* ___0_username, String_t* ___1_password, String_t* ___2_realm, String_t* ___3_nonce, String_t* ___4_cnonce, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral17490F55601C1F90A7803263837FE3F21E759D69);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	String_t* V_1 = NULL;
	{
		String_t* L_0 = ___0_username;
		String_t* L_1 = ___1_password;
		String_t* L_2 = ___2_realm;
		String_t* L_3;
		L_3 = AuthenticationResponse_createA1_m0CDAB5F5A670DEDD5B42F6E5A20104090AC7EAC7(L_0, L_1, L_2, NULL);
		V_0 = L_3;
		String_t* L_4 = V_0;
		String_t* L_5;
		L_5 = AuthenticationResponse_hash_m0678824675277D1E5BE17B591BC904438B65101E(L_4, NULL);
		String_t* L_6 = ___3_nonce;
		String_t* L_7 = ___4_cnonce;
		String_t* L_8;
		L_8 = String_Format_mA0534D6E2AE4D67A6BD8D45B3321323930EB930C(_stringLiteral17490F55601C1F90A7803263837FE3F21E759D69, L_5, L_6, L_7, NULL);
		V_1 = L_8;
		goto IL_0020;
	}

IL_0020:
	{
		String_t* L_9 = V_1;
		return L_9;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_createA2_mA63C37736C690B00F5F9E4B6CDE2F9EDB5BF59BD (String_t* ___0_method, String_t* ___1_uri, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralAD6CD2C36915DEB6A18BCF0F46B294FC1D97072F);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		String_t* L_0 = ___0_method;
		String_t* L_1 = ___1_uri;
		String_t* L_2;
		L_2 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteralAD6CD2C36915DEB6A18BCF0F46B294FC1D97072F, L_0, L_1, NULL);
		V_0 = L_2;
		goto IL_0010;
	}

IL_0010:
	{
		String_t* L_3 = V_0;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_createA2_m75EC602C7BA6964BA905202C6F0AA5B37B1080A0 (String_t* ___0_method, String_t* ___1_uri, String_t* ___2_entity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral17490F55601C1F90A7803263837FE3F21E759D69);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		String_t* L_0 = ___0_method;
		String_t* L_1 = ___1_uri;
		String_t* L_2 = ___2_entity;
		String_t* L_3;
		L_3 = AuthenticationResponse_hash_m0678824675277D1E5BE17B591BC904438B65101E(L_2, NULL);
		String_t* L_4;
		L_4 = String_Format_mA0534D6E2AE4D67A6BD8D45B3321323930EB930C(_stringLiteral17490F55601C1F90A7803263837FE3F21E759D69, L_0, L_1, L_3, NULL);
		V_0 = L_4;
		goto IL_0016;
	}

IL_0016:
	{
		String_t* L_5 = V_0;
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_hash_m0678824675277D1E5BE17B591BC904438B65101E (String_t* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral65A0F9B64ACE7C859A284EA54B1190CBF83E1260);
		s_Il2CppMethodInitialized = true;
	}
	MD5_t808E6AE387D5FCC368DBB86576572C1564D17E5A* V_0 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_1 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_2 = NULL;
	StringBuilder_t* V_3 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_4 = NULL;
	int32_t V_5 = 0;
	uint8_t V_6 = 0x0;
	String_t* V_7 = NULL;
	{
		MD5_t808E6AE387D5FCC368DBB86576572C1564D17E5A* L_0;
		L_0 = MD5_Create_mD7AEBE7A752D163971C764A9A8CC0029C865F223(NULL);
		V_0 = L_0;
		Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_1;
		L_1 = Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9(NULL);
		String_t* L_2 = ___0_value;
		NullCheck(L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3;
		L_3 = VirtualFuncInvoker1< ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, String_t* >::Invoke(16, L_1, L_2);
		V_1 = L_3;
		MD5_t808E6AE387D5FCC368DBB86576572C1564D17E5A* L_4 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_1;
		NullCheck(L_4);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6;
		L_6 = HashAlgorithm_ComputeHash_mC9CD24714D75A8D61F12509BF952A26347FF22FB(L_4, L_5, NULL);
		V_2 = L_6;
		StringBuilder_t* L_7 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m2619CA8D2C3476DF1A302D9D941498BB1C6164C5(L_7, ((int32_t)64), NULL);
		V_3 = L_7;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8 = V_2;
		V_4 = L_8;
		V_5 = 0;
		goto IL_004c;
	}

IL_002c:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_4;
		int32_t L_10 = V_5;
		NullCheck(L_9);
		int32_t L_11 = L_10;
		uint8_t L_12 = (L_9)->GetAt(static_cast<il2cpp_array_size_t>(L_11));
		V_6 = L_12;
		StringBuilder_t* L_13 = V_3;
		String_t* L_14;
		L_14 = Byte_ToString_m793A41EEEB7B422F6FE658E99D2F7683F59EE310((&V_6), _stringLiteral65A0F9B64ACE7C859A284EA54B1190CBF83E1260, NULL);
		NullCheck(L_13);
		StringBuilder_t* L_15;
		L_15 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_13, L_14, NULL);
		int32_t L_16 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_16, 1));
	}

IL_004c:
	{
		int32_t L_17 = V_5;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_18 = V_4;
		NullCheck(L_18);
		if ((((int32_t)L_17) < ((int32_t)((int32_t)(((RuntimeArray*)L_18)->max_length)))))
		{
			goto IL_002c;
		}
	}
	{
		StringBuilder_t* L_19 = V_3;
		NullCheck(L_19);
		String_t* L_20;
		L_20 = VirtualFuncInvoker0< String_t* >::Invoke(3, L_19);
		V_7 = L_20;
		goto IL_005e;
	}

IL_005e:
	{
		String_t* L_21 = V_7;
		return L_21;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AuthenticationResponse_initAsDigest_mF1764BF15FCAD903AC6E134D8CBF333E8DD9319B (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Ext_Contains_TisString_t_m21F17700FD2F34406CD7C4E4606CAF47F5D9CE17_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Ext_t6D7C499436D2B147B941E873C73C930E159B53D0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_U3CinitAsDigestU3Eb__40_0_m894815231F6A859B84DBD42CED0C64A3C3405DE7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1C93369986E246DFCCD8F0F4ED253F8B083E300C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2C410EB1F22365EC1A74DF0D8C89C99D53453CDD);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3781CFEEF925855A4B7284E1783A7D715A6333F6);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral56527A2300BB0A611AE7B1418C0BFCB781C48103);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral606A7CE0F9FFB91FC58BD3742461F2EC0C39C4B4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral82EA3C9AFC08F0CECEBC1B257606B3106346FCAF);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD555DED7CEC14AAFD2389F4CA5DB31942645053F);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF7A27446F990E86AFC16857987F96B66843F2912);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	uint32_t V_4 = 0;
	Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D* G_B3_0 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B3_1 = NULL;
	Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D* G_B2_0 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B2_1 = NULL;
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_0 = __this->____parameters;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_0, _stringLiteral56527A2300BB0A611AE7B1418C0BFCB781C48103, NULL);
		V_0 = L_1;
		String_t* L_2 = V_0;
		V_1 = (bool)((!(((RuntimeObject*)(String_t*)L_2) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_00d2;
		}
	}
	{
		String_t* L_4 = V_0;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_5 = (CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)SZArrayNew(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB_il2cpp_TypeInfo_var, (uint32_t)1);
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_6 = L_5;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(0), (Il2CppChar)((int32_t)44));
		NullCheck(L_4);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_7;
		L_7 = String_Split_m101D35FEC86371D2BB4E3480F6F896880093B2E9(L_4, L_6, NULL);
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_il2cpp_TypeInfo_var);
		Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D* L_8 = ((U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_il2cpp_TypeInfo_var))->___U3CU3E9__40_0;
		Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D* L_9 = L_8;
		if (L_9)
		{
			G_B3_0 = L_9;
			G_B3_1 = L_7;
			goto IL_004e;
		}
		G_B2_0 = L_9;
		G_B2_1 = L_7;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_il2cpp_TypeInfo_var);
		U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55* L_10 = ((U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_il2cpp_TypeInfo_var))->___U3CU3E9;
		Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D* L_11 = (Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D*)il2cpp_codegen_object_new(Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D_il2cpp_TypeInfo_var);
		Func_2__ctor_m247D5044A4E1F518CA84A38B9A9F30E66BDD8184(L_11, L_10, (intptr_t)((void*)U3CU3Ec_U3CinitAsDigestU3Eb__40_0_m894815231F6A859B84DBD42CED0C64A3C3405DE7_RuntimeMethod_var), NULL);
		Func_2_tAB9727E0C937894E19032D575D98A8A9AB5EE47D* L_12 = L_11;
		((U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_il2cpp_TypeInfo_var))->___U3CU3E9__40_0 = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_il2cpp_TypeInfo_var))->___U3CU3E9__40_0), (void*)L_12);
		G_B3_0 = L_12;
		G_B3_1 = G_B2_1;
	}

IL_004e:
	{
		il2cpp_codegen_runtime_class_init_inline(Ext_t6D7C499436D2B147B941E873C73C930E159B53D0_il2cpp_TypeInfo_var);
		bool L_13;
		L_13 = Ext_Contains_TisString_t_m21F17700FD2F34406CD7C4E4606CAF47F5D9CE17((RuntimeObject*)G_B3_1, G_B3_0, Ext_Contains_TisString_t_m21F17700FD2F34406CD7C4E4606CAF47F5D9CE17_RuntimeMethod_var);
		V_2 = L_13;
		bool L_14 = V_2;
		V_3 = L_14;
		bool L_15 = V_3;
		if (!L_15)
		{
			goto IL_00bd;
		}
	}
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_16 = __this->____parameters;
		NullCheck(L_16);
		NameValueCollection_set_Item_mEEC24334890E9C0A05B88638B6A65DF5D888B0B0(L_16, _stringLiteral56527A2300BB0A611AE7B1418C0BFCB781C48103, _stringLiteralD555DED7CEC14AAFD2389F4CA5DB31942645053F, NULL);
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_17 = __this->____parameters;
		String_t* L_18;
		L_18 = AuthenticationChallenge_CreateNonceValue_mD99400D9BE382F60C645D8C6C17FE1B34BBE14BC(NULL);
		NullCheck(L_17);
		NameValueCollection_set_Item_mEEC24334890E9C0A05B88638B6A65DF5D888B0B0(L_17, _stringLiteral606A7CE0F9FFB91FC58BD3742461F2EC0C39C4B4, L_18, NULL);
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_19 = __this->____parameters;
		uint32_t L_20 = __this->____nonceCount;
		V_4 = ((int32_t)il2cpp_codegen_add((int32_t)L_20, 1));
		uint32_t L_21 = V_4;
		__this->____nonceCount = L_21;
		uint32_t L_22 = V_4;
		uint32_t L_23 = L_22;
		RuntimeObject* L_24 = Box(UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var, &L_23);
		String_t* L_25;
		L_25 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(_stringLiteralF7A27446F990E86AFC16857987F96B66843F2912, L_24, NULL);
		NullCheck(L_19);
		NameValueCollection_set_Item_mEEC24334890E9C0A05B88638B6A65DF5D888B0B0(L_19, _stringLiteral1C93369986E246DFCCD8F0F4ED253F8B083E300C, L_25, NULL);
		goto IL_00d1;
	}

IL_00bd:
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_26 = __this->____parameters;
		NullCheck(L_26);
		NameValueCollection_set_Item_mEEC24334890E9C0A05B88638B6A65DF5D888B0B0(L_26, _stringLiteral56527A2300BB0A611AE7B1418C0BFCB781C48103, (String_t*)NULL, NULL);
	}

IL_00d1:
	{
	}

IL_00d2:
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_27 = __this->____parameters;
		NullCheck(L_27);
		NameValueCollection_set_Item_mEEC24334890E9C0A05B88638B6A65DF5D888B0B0(L_27, _stringLiteral82EA3C9AFC08F0CECEBC1B257606B3106346FCAF, _stringLiteral3781CFEEF925855A4B7284E1783A7D715A6333F6, NULL);
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_28 = __this->____parameters;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_29 = __this->____parameters;
		String_t* L_30;
		L_30 = AuthenticationResponse_CreateRequestDigest_mF55FF510E22D3C634F08915B5253D27227E0266F(L_29, NULL);
		NullCheck(L_28);
		NameValueCollection_set_Item_mEEC24334890E9C0A05B88638B6A65DF5D888B0B0(L_28, _stringLiteral2C410EB1F22365EC1A74DF0D8C89C99D53453CDD, L_30, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_CreateRequestDigest_mF55FF510E22D3C634F08915B5253D27227E0266F (NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* ___0_parameters, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral10C63C8C602DD5E38BE4A758C90EBAC324CD3E69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1C93369986E246DFCCD8F0F4ED253F8B083E300C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2555543242A278889EA1F704BD696770579E9304);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral335CA71010F7EFAB270E1E0D36EFB78000B60FF2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral56527A2300BB0A611AE7B1418C0BFCB781C48103);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral606A7CE0F9FFB91FC58BD3742461F2EC0C39C4B4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral82EA3C9AFC08F0CECEBC1B257606B3106346FCAF);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA9AF8D13B64E63A31A01386E007E5C9CF3A6CF5B);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralAD6CD2C36915DEB6A18BCF0F46B294FC1D97072F);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7D1CAF9B55BE135BC8B1C459D2052FBCF135556);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBBBCFF9559F03CF35B40795127B3BDBC6A80E8CB);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE3A56BE62F0FB42D8062A17A4957C2142D815735);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE8F97FBA9104D1EA5047948E6DFB67FACD9F5B73);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF94826EFCA9D0B0B714BFAF666209B973B2B4730);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFE55A44A4569E37676CECA70D4046727B22CA6A6);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	String_t* V_1 = NULL;
	String_t* V_2 = NULL;
	String_t* V_3 = NULL;
	String_t* V_4 = NULL;
	String_t* V_5 = NULL;
	String_t* V_6 = NULL;
	String_t* V_7 = NULL;
	String_t* V_8 = NULL;
	String_t* V_9 = NULL;
	String_t* V_10 = NULL;
	String_t* V_11 = NULL;
	String_t* V_12 = NULL;
	String_t* V_13 = NULL;
	String_t* V_14 = NULL;
	String_t* V_15 = NULL;
	String_t* G_B4_0 = NULL;
	String_t* G_B8_0 = NULL;
	String_t* G_B11_0 = NULL;
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_0 = ___0_parameters;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_0, _stringLiteralE3A56BE62F0FB42D8062A17A4957C2142D815735, NULL);
		V_0 = L_1;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_2 = ___0_parameters;
		NullCheck(L_2);
		String_t* L_3;
		L_3 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_2, _stringLiteralE8F97FBA9104D1EA5047948E6DFB67FACD9F5B73, NULL);
		V_1 = L_3;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_4 = ___0_parameters;
		NullCheck(L_4);
		String_t* L_5;
		L_5 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_4, _stringLiteralB7D1CAF9B55BE135BC8B1C459D2052FBCF135556, NULL);
		V_2 = L_5;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_6 = ___0_parameters;
		NullCheck(L_6);
		String_t* L_7;
		L_7 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_6, _stringLiteral2555543242A278889EA1F704BD696770579E9304, NULL);
		V_3 = L_7;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_8 = ___0_parameters;
		NullCheck(L_8);
		String_t* L_9;
		L_9 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_8, _stringLiteral10C63C8C602DD5E38BE4A758C90EBAC324CD3E69, NULL);
		V_4 = L_9;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_10 = ___0_parameters;
		NullCheck(L_10);
		String_t* L_11;
		L_11 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_10, _stringLiteralA9AF8D13B64E63A31A01386E007E5C9CF3A6CF5B, NULL);
		V_5 = L_11;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_12 = ___0_parameters;
		NullCheck(L_12);
		String_t* L_13;
		L_13 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_12, _stringLiteral56527A2300BB0A611AE7B1418C0BFCB781C48103, NULL);
		V_6 = L_13;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_14 = ___0_parameters;
		NullCheck(L_14);
		String_t* L_15;
		L_15 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_14, _stringLiteral606A7CE0F9FFB91FC58BD3742461F2EC0C39C4B4, NULL);
		V_7 = L_15;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_16 = ___0_parameters;
		NullCheck(L_16);
		String_t* L_17;
		L_17 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_16, _stringLiteral1C93369986E246DFCCD8F0F4ED253F8B083E300C, NULL);
		V_8 = L_17;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_18 = ___0_parameters;
		NullCheck(L_18);
		String_t* L_19;
		L_19 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_18, _stringLiteral82EA3C9AFC08F0CECEBC1B257606B3106346FCAF, NULL);
		V_9 = L_19;
		String_t* L_20 = V_5;
		if (!L_20)
		{
			goto IL_0096;
		}
	}
	{
		String_t* L_21 = V_5;
		NullCheck(L_21);
		String_t* L_22;
		L_22 = String_ToLower_m6191ABA3DC514ED47C10BDA23FD0DDCEAE7ACFBD(L_21, NULL);
		bool L_23;
		L_23 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_22, _stringLiteralFE55A44A4569E37676CECA70D4046727B22CA6A6, NULL);
		if (L_23)
		{
			goto IL_00a0;
		}
	}

IL_0096:
	{
		String_t* L_24 = V_0;
		String_t* L_25 = V_1;
		String_t* L_26 = V_2;
		String_t* L_27;
		L_27 = AuthenticationResponse_createA1_m0CDAB5F5A670DEDD5B42F6E5A20104090AC7EAC7(L_24, L_25, L_26, NULL);
		G_B4_0 = L_27;
		goto IL_00ab;
	}

IL_00a0:
	{
		String_t* L_28 = V_0;
		String_t* L_29 = V_1;
		String_t* L_30 = V_2;
		String_t* L_31 = V_3;
		String_t* L_32 = V_7;
		String_t* L_33;
		L_33 = AuthenticationResponse_createA1_mE47ADA8DD33D193F8656E6DF7FACAFDDF36FC37C(L_28, L_29, L_30, L_31, L_32, NULL);
		G_B4_0 = L_33;
	}

IL_00ab:
	{
		V_10 = G_B4_0;
		String_t* L_34 = V_6;
		if (!L_34)
		{
			goto IL_00c4;
		}
	}
	{
		String_t* L_35 = V_6;
		NullCheck(L_35);
		String_t* L_36;
		L_36 = String_ToLower_m6191ABA3DC514ED47C10BDA23FD0DDCEAE7ACFBD(L_35, NULL);
		bool L_37;
		L_37 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_36, _stringLiteral335CA71010F7EFAB270E1E0D36EFB78000B60FF2, NULL);
		if (L_37)
		{
			goto IL_00cf;
		}
	}

IL_00c4:
	{
		String_t* L_38 = V_9;
		String_t* L_39 = V_4;
		String_t* L_40;
		L_40 = AuthenticationResponse_createA2_mA63C37736C690B00F5F9E4B6CDE2F9EDB5BF59BD(L_38, L_39, NULL);
		G_B8_0 = L_40;
		goto IL_00e3;
	}

IL_00cf:
	{
		String_t* L_41 = V_9;
		String_t* L_42 = V_4;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_43 = ___0_parameters;
		NullCheck(L_43);
		String_t* L_44;
		L_44 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_43, _stringLiteralBBBCFF9559F03CF35B40795127B3BDBC6A80E8CB, NULL);
		String_t* L_45;
		L_45 = AuthenticationResponse_createA2_m75EC602C7BA6964BA905202C6F0AA5B37B1080A0(L_41, L_42, L_44, NULL);
		G_B8_0 = L_45;
	}

IL_00e3:
	{
		V_11 = G_B8_0;
		String_t* L_46 = V_10;
		String_t* L_47;
		L_47 = AuthenticationResponse_hash_m0678824675277D1E5BE17B591BC904438B65101E(L_46, NULL);
		V_12 = L_47;
		String_t* L_48 = V_6;
		if (L_48)
		{
			goto IL_0106;
		}
	}
	{
		String_t* L_49 = V_3;
		String_t* L_50 = V_11;
		String_t* L_51;
		L_51 = AuthenticationResponse_hash_m0678824675277D1E5BE17B591BC904438B65101E(L_50, NULL);
		String_t* L_52;
		L_52 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteralAD6CD2C36915DEB6A18BCF0F46B294FC1D97072F, L_49, L_51, NULL);
		G_B11_0 = L_52;
		goto IL_0133;
	}

IL_0106:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_53 = (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)SZArrayNew(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var, (uint32_t)5);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_54 = L_53;
		String_t* L_55 = V_3;
		NullCheck(L_54);
		ArrayElementTypeCheck (L_54, L_55);
		(L_54)->SetAt(static_cast<il2cpp_array_size_t>(0), (RuntimeObject*)L_55);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_56 = L_54;
		String_t* L_57 = V_8;
		NullCheck(L_56);
		ArrayElementTypeCheck (L_56, L_57);
		(L_56)->SetAt(static_cast<il2cpp_array_size_t>(1), (RuntimeObject*)L_57);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_58 = L_56;
		String_t* L_59 = V_7;
		NullCheck(L_58);
		ArrayElementTypeCheck (L_58, L_59);
		(L_58)->SetAt(static_cast<il2cpp_array_size_t>(2), (RuntimeObject*)L_59);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_60 = L_58;
		String_t* L_61 = V_6;
		NullCheck(L_60);
		ArrayElementTypeCheck (L_60, L_61);
		(L_60)->SetAt(static_cast<il2cpp_array_size_t>(3), (RuntimeObject*)L_61);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_62 = L_60;
		String_t* L_63 = V_11;
		String_t* L_64;
		L_64 = AuthenticationResponse_hash_m0678824675277D1E5BE17B591BC904438B65101E(L_63, NULL);
		NullCheck(L_62);
		ArrayElementTypeCheck (L_62, L_64);
		(L_62)->SetAt(static_cast<il2cpp_array_size_t>(4), (RuntimeObject*)L_64);
		String_t* L_65;
		L_65 = String_Format_m918500C1EFB475181349A79989BB79BB36102894(_stringLiteralF94826EFCA9D0B0B714BFAF666209B973B2B4730, L_62, NULL);
		G_B11_0 = L_65;
	}

IL_0133:
	{
		V_13 = G_B11_0;
		String_t* L_66 = V_12;
		String_t* L_67 = V_13;
		String_t* L_68;
		L_68 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteralAD6CD2C36915DEB6A18BCF0F46B294FC1D97072F, L_66, L_67, NULL);
		V_14 = L_68;
		String_t* L_69 = V_14;
		String_t* L_70;
		L_70 = AuthenticationResponse_hash_m0678824675277D1E5BE17B591BC904438B65101E(L_69, NULL);
		V_15 = L_70;
		goto IL_0150;
	}

IL_0150:
	{
		String_t* L_71 = V_15;
		return L_71;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_ToBasicString_mF1E66F0E9ECBDCCD2AA2D2644E8DAB6154BF3753 (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9EB642385221D006B3B8DB45C10F626FD2A3DB7C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralAD6CD2C36915DEB6A18BCF0F46B294FC1D97072F);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE3A56BE62F0FB42D8062A17A4957C2142D815735);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE8F97FBA9104D1EA5047948E6DFB67FACD9F5B73);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	String_t* V_1 = NULL;
	String_t* V_2 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_3 = NULL;
	String_t* V_4 = NULL;
	String_t* V_5 = NULL;
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_0 = __this->____parameters;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_0, _stringLiteralE3A56BE62F0FB42D8062A17A4957C2142D815735, NULL);
		V_0 = L_1;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_2 = __this->____parameters;
		NullCheck(L_2);
		String_t* L_3;
		L_3 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_2, _stringLiteralE8F97FBA9104D1EA5047948E6DFB67FACD9F5B73, NULL);
		V_1 = L_3;
		String_t* L_4 = V_0;
		String_t* L_5 = V_1;
		String_t* L_6;
		L_6 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteralAD6CD2C36915DEB6A18BCF0F46B294FC1D97072F, L_4, L_5, NULL);
		V_2 = L_6;
		Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_7;
		L_7 = Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9(NULL);
		String_t* L_8 = V_2;
		NullCheck(L_7);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9;
		L_9 = VirtualFuncInvoker1< ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, String_t* >::Invoke(16, L_7, L_8);
		V_3 = L_9;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_10 = V_3;
		il2cpp_codegen_runtime_class_init_inline(Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		String_t* L_11;
		L_11 = Convert_ToBase64String_mD0680EF77270244071965AFA1207921C73EEA323(L_10, NULL);
		V_4 = L_11;
		String_t* L_12 = V_4;
		String_t* L_13;
		L_13 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral9EB642385221D006B3B8DB45C10F626FD2A3DB7C, L_12, NULL);
		V_5 = L_13;
		goto IL_0054;
	}

IL_0054:
	{
		String_t* L_14 = V_5;
		return L_14;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_ToDigestString_m0FA5FA3FAEB1C8C2FE9E73424DE18C615CFF558F (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral10C63C8C602DD5E38BE4A758C90EBAC324CD3E69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1C93369986E246DFCCD8F0F4ED253F8B083E300C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2555543242A278889EA1F704BD696770579E9304);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2958EF457D5998322D06906E8D46C16545F1EAD8);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2C410EB1F22365EC1A74DF0D8C89C99D53453CDD);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral56527A2300BB0A611AE7B1418C0BFCB781C48103);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral59A9856ADD5A93479660B0DADE65D1636B473A27);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral606A7CE0F9FFB91FC58BD3742461F2EC0C39C4B4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9C35BA15FC8288F6F7A229DD42F48D4FB70DCC2E);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA9AF8D13B64E63A31A01386E007E5C9CF3A6CF5B);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7D1CAF9B55BE135BC8B1C459D2052FBCF135556);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE3A56BE62F0FB42D8062A17A4957C2142D815735);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE806CD6CD3D351202351C73AC5A552506A239F67);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFD5D7F52F77675FA28D319961C4D67C43045195A);
		s_Il2CppMethodInitialized = true;
	}
	StringBuilder_t* V_0 = NULL;
	String_t* V_1 = NULL;
	String_t* V_2 = NULL;
	String_t* V_3 = NULL;
	String_t* V_4 = NULL;
	String_t* V_5 = NULL;
	String_t* V_6 = NULL;
	String_t* V_7 = NULL;
	String_t* V_8 = NULL;
	bool V_9 = false;
	bool V_10 = false;
	bool V_11 = false;
	String_t* V_12 = NULL;
	String_t* V_13 = NULL;
	String_t* V_14 = NULL;
	{
		StringBuilder_t* L_0 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m2619CA8D2C3476DF1A302D9D941498BB1C6164C5(L_0, ((int32_t)256), NULL);
		V_0 = L_0;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_1 = __this->____parameters;
		NullCheck(L_1);
		String_t* L_2;
		L_2 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_1, _stringLiteralE3A56BE62F0FB42D8062A17A4957C2142D815735, NULL);
		V_1 = L_2;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_3 = __this->____parameters;
		NullCheck(L_3);
		String_t* L_4;
		L_4 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_3, _stringLiteralB7D1CAF9B55BE135BC8B1C459D2052FBCF135556, NULL);
		V_2 = L_4;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_5 = __this->____parameters;
		NullCheck(L_5);
		String_t* L_6;
		L_6 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_5, _stringLiteral2555543242A278889EA1F704BD696770579E9304, NULL);
		V_3 = L_6;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_7 = __this->____parameters;
		NullCheck(L_7);
		String_t* L_8;
		L_8 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_7, _stringLiteral10C63C8C602DD5E38BE4A758C90EBAC324CD3E69, NULL);
		V_4 = L_8;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_9 = __this->____parameters;
		NullCheck(L_9);
		String_t* L_10;
		L_10 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_9, _stringLiteral2C410EB1F22365EC1A74DF0D8C89C99D53453CDD, NULL);
		V_5 = L_10;
		StringBuilder_t* L_11 = V_0;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_12 = (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)SZArrayNew(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var, (uint32_t)5);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_13 = L_12;
		String_t* L_14 = V_1;
		NullCheck(L_13);
		ArrayElementTypeCheck (L_13, L_14);
		(L_13)->SetAt(static_cast<il2cpp_array_size_t>(0), (RuntimeObject*)L_14);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_15 = L_13;
		String_t* L_16 = V_2;
		NullCheck(L_15);
		ArrayElementTypeCheck (L_15, L_16);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(1), (RuntimeObject*)L_16);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_17 = L_15;
		String_t* L_18 = V_3;
		NullCheck(L_17);
		ArrayElementTypeCheck (L_17, L_18);
		(L_17)->SetAt(static_cast<il2cpp_array_size_t>(2), (RuntimeObject*)L_18);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_19 = L_17;
		String_t* L_20 = V_4;
		NullCheck(L_19);
		ArrayElementTypeCheck (L_19, L_20);
		(L_19)->SetAt(static_cast<il2cpp_array_size_t>(3), (RuntimeObject*)L_20);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_21 = L_19;
		String_t* L_22 = V_5;
		NullCheck(L_21);
		ArrayElementTypeCheck (L_21, L_22);
		(L_21)->SetAt(static_cast<il2cpp_array_size_t>(4), (RuntimeObject*)L_22);
		NullCheck(L_11);
		StringBuilder_t* L_23;
		L_23 = StringBuilder_AppendFormat_m14CB447291E6149BCF32E5E37DA21514BAD9C151(L_11, _stringLiteral2958EF457D5998322D06906E8D46C16545F1EAD8, L_21, NULL);
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_24 = __this->____parameters;
		NullCheck(L_24);
		String_t* L_25;
		L_25 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_24, _stringLiteral9C35BA15FC8288F6F7A229DD42F48D4FB70DCC2E, NULL);
		V_6 = L_25;
		String_t* L_26 = V_6;
		V_9 = (bool)((!(((RuntimeObject*)(String_t*)L_26) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_27 = V_9;
		if (!L_27)
		{
			goto IL_00b6;
		}
	}
	{
		StringBuilder_t* L_28 = V_0;
		String_t* L_29 = V_6;
		NullCheck(L_28);
		StringBuilder_t* L_30;
		L_30 = StringBuilder_AppendFormat_mFA88863E4018C2912D1A783E0EA6DAE4F594124F(L_28, _stringLiteral59A9856ADD5A93479660B0DADE65D1636B473A27, L_29, NULL);
	}

IL_00b6:
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_31 = __this->____parameters;
		NullCheck(L_31);
		String_t* L_32;
		L_32 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_31, _stringLiteralA9AF8D13B64E63A31A01386E007E5C9CF3A6CF5B, NULL);
		V_7 = L_32;
		String_t* L_33 = V_7;
		V_10 = (bool)((!(((RuntimeObject*)(String_t*)L_33) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_34 = V_10;
		if (!L_34)
		{
			goto IL_00e1;
		}
	}
	{
		StringBuilder_t* L_35 = V_0;
		String_t* L_36 = V_7;
		NullCheck(L_35);
		StringBuilder_t* L_37;
		L_37 = StringBuilder_AppendFormat_mFA88863E4018C2912D1A783E0EA6DAE4F594124F(L_35, _stringLiteralE806CD6CD3D351202351C73AC5A552506A239F67, L_36, NULL);
	}

IL_00e1:
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_38 = __this->____parameters;
		NullCheck(L_38);
		String_t* L_39;
		L_39 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_38, _stringLiteral56527A2300BB0A611AE7B1418C0BFCB781C48103, NULL);
		V_8 = L_39;
		String_t* L_40 = V_8;
		V_11 = (bool)((!(((RuntimeObject*)(String_t*)L_40) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_41 = V_11;
		if (!L_41)
		{
			goto IL_0136;
		}
	}
	{
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_42 = __this->____parameters;
		NullCheck(L_42);
		String_t* L_43;
		L_43 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_42, _stringLiteral606A7CE0F9FFB91FC58BD3742461F2EC0C39C4B4, NULL);
		V_12 = L_43;
		NameValueCollection_t52D1E38AB1D4ADD497A17DA305D663BB77B31DF7* L_44 = __this->____parameters;
		NullCheck(L_44);
		String_t* L_45;
		L_45 = NameValueCollection_get_Item_mE3ED755803E67BC852123C70EEF8D53774FA635F(L_44, _stringLiteral1C93369986E246DFCCD8F0F4ED253F8B083E300C, NULL);
		V_13 = L_45;
		StringBuilder_t* L_46 = V_0;
		String_t* L_47 = V_8;
		String_t* L_48 = V_12;
		String_t* L_49 = V_13;
		NullCheck(L_46);
		StringBuilder_t* L_50;
		L_50 = StringBuilder_AppendFormat_m40962B9C5B41720C6424721E526C0D99D95112A2(L_46, _stringLiteralFD5D7F52F77675FA28D319961C4D67C43045195A, L_47, L_48, L_49, NULL);
	}

IL_0136:
	{
		StringBuilder_t* L_51 = V_0;
		NullCheck(L_51);
		String_t* L_52;
		L_52 = VirtualFuncInvoker0< String_t* >::Invoke(3, L_51);
		V_14 = L_52;
		goto IL_0140;
	}

IL_0140:
	{
		String_t* L_53 = V_14;
		return L_53;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AuthenticationResponse_ToString_mC43C99FAE145944BCA8F9CAB95C00C1C1DBA5FAE (AuthenticationResponse_t50F8680C8D040A2432CAFF99A7613EC28BF96B9F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	String_t* V_1 = NULL;
	bool V_2 = false;
	{
		int32_t L_0 = __this->____scheme;
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)8))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0017;
		}
	}
	{
		String_t* L_2;
		L_2 = AuthenticationResponse_ToBasicString_mF1E66F0E9ECBDCCD2AA2D2644E8DAB6154BF3753(__this, NULL);
		V_1 = L_2;
		goto IL_0035;
	}

IL_0017:
	{
		int32_t L_3 = __this->____scheme;
		V_2 = (bool)((((int32_t)L_3) == ((int32_t)1))? 1 : 0);
		bool L_4 = V_2;
		if (!L_4)
		{
			goto IL_002d;
		}
	}
	{
		String_t* L_5;
		L_5 = AuthenticationResponse_ToDigestString_m0FA5FA3FAEB1C8C2FE9E73424DE18C615CFF558F(__this, NULL);
		V_1 = L_5;
		goto IL_0035;
	}

IL_002d:
	{
		String_t* L_6 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty;
		V_1 = L_6;
		goto IL_0035;
	}

IL_0035:
	{
		String_t* L_7 = V_1;
		return L_7;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__cctor_m5817497C331EBF1A56F3CC22EFBCAFB0100CDE46 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55* L_0 = (U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55*)il2cpp_codegen_object_new(U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_il2cpp_TypeInfo_var);
		U3CU3Ec__ctor_m3455993C477A48D7DE97292F29F21BF3CCDDAB53(L_0, NULL);
		((U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_il2cpp_TypeInfo_var))->___U3CU3E9 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55_il2cpp_TypeInfo_var))->___U3CU3E9), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__ctor_m3455993C477A48D7DE97292F29F21BF3CCDDAB53 (U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CU3Ec_U3CinitAsDigestU3Eb__40_0_m894815231F6A859B84DBD42CED0C64A3C3405DE7 (U3CU3Ec_tE2D8F74F341CCB8520DBC4D6794204BFA3846F55* __this, String_t* ___0_qop, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD555DED7CEC14AAFD2389F4CA5DB31942645053F);
		s_Il2CppMethodInitialized = true;
	}
	{
		String_t* L_0 = ___0_qop;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = String_Trim_mCD6D8C6D4CFD15225D12DB7D3E0544CA80FB8DA5(L_0, NULL);
		NullCheck(L_1);
		String_t* L_2;
		L_2 = String_ToLower_m6191ABA3DC514ED47C10BDA23FD0DDCEAE7ACFBD(L_1, NULL);
		bool L_3;
		L_3 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_2, _stringLiteralD555DED7CEC14AAFD2389F4CA5DB31942645053F, NULL);
		return L_3;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ClientSslConfiguration__ctor_mB1979618DD244BF728A013D2FDC7F8D19110F13C (ClientSslConfiguration_t212ECC383B70D9C462DC423E9D3CD27C9E74A603* __this, String_t* ___0_targetHost, const RuntimeMethod* method) 
{
	bool V_0 = false;
	bool V_1 = false;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		String_t* L_0 = ___0_targetHost;
		V_0 = (bool)((((RuntimeObject*)(String_t*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_001b;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_2 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral31FA596F0CB831B1917230C3D7C170B60B5F0398)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ClientSslConfiguration__ctor_mB1979618DD244BF728A013D2FDC7F8D19110F13C_RuntimeMethod_var)));
	}

IL_001b:
	{
		String_t* L_3 = ___0_targetHost;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_3, NULL);
		V_1 = (bool)((((int32_t)L_4) == ((int32_t)0))? 1 : 0);
		bool L_5 = V_1;
		if (!L_5)
		{
			goto IL_0038;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_6 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral000782DE5F1D05B671170917E3CF2EE86FCE6F55)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral31FA596F0CB831B1917230C3D7C170B60B5F0398)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ClientSslConfiguration__ctor_mB1979618DD244BF728A013D2FDC7F8D19110F13C_RuntimeMethod_var)));
	}

IL_0038:
	{
		String_t* L_7 = ___0_targetHost;
		__this->____targetHost = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____targetHost), (void*)L_7);
		__this->____enabledSslProtocols = 0;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ClientSslConfiguration_get_CheckCertificateRevocation_mB4DA43164D1A7303E7BDEA401E7815CBF0BB5D06 (ClientSslConfiguration_t212ECC383B70D9C462DC423E9D3CD27C9E74A603* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		bool L_0 = __this->____checkCertRevocation;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		bool L_1 = V_0;
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR X509CertificateCollection_t2900D71D188EDCA7DEB5077D36103EE5DA6805CE* ClientSslConfiguration_get_ClientCertificates_m2EBB365FA470CBCADF01E8FA26682612AA36B637 (ClientSslConfiguration_t212ECC383B70D9C462DC423E9D3CD27C9E74A603* __this, const RuntimeMethod* method) 
{
	X509CertificateCollection_t2900D71D188EDCA7DEB5077D36103EE5DA6805CE* V_0 = NULL;
	{
		X509CertificateCollection_t2900D71D188EDCA7DEB5077D36103EE5DA6805CE* L_0 = __this->____clientCerts;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		X509CertificateCollection_t2900D71D188EDCA7DEB5077D36103EE5DA6805CE* L_1 = V_0;
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859* ClientSslConfiguration_get_ClientCertificateSelectionCallback_m0BE8FDC7FCFF0CD835AC7DE3EDDF5F3C803F8DB2 (ClientSslConfiguration_t212ECC383B70D9C462DC423E9D3CD27C9E74A603* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ClientSslConfiguration_defaultSelectClientCertificate_mA37A39560426481E9ADA0F9DDC7617E58E9732D5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859* V_1 = NULL;
	{
		LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859* L_0 = __this->____clientCertSelectionCallback;
		V_0 = (bool)((((RuntimeObject*)(LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0020;
		}
	}
	{
		LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859* L_2 = (LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859*)il2cpp_codegen_object_new(LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859_il2cpp_TypeInfo_var);
		LocalCertificateSelectionCallback__ctor_mE4F3A8BFF483881C2634112BB581CA4B07809805(L_2, NULL, (intptr_t)((void*)ClientSslConfiguration_defaultSelectClientCertificate_mA37A39560426481E9ADA0F9DDC7617E58E9732D5_RuntimeMethod_var), NULL);
		__this->____clientCertSelectionCallback = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____clientCertSelectionCallback), (void*)L_2);
	}

IL_0020:
	{
		LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859* L_3 = __this->____clientCertSelectionCallback;
		V_1 = L_3;
		goto IL_0029;
	}

IL_0029:
	{
		LocalCertificateSelectionCallback_t71A03329606A5610ECC62BFBE6327C1EF9195859* L_4 = V_1;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ClientSslConfiguration_get_EnabledSslProtocols_mE97E1B7BEE56BD287C5000968ACB0614C512502A (ClientSslConfiguration_t212ECC383B70D9C462DC423E9D3CD27C9E74A603* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____enabledSslProtocols;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		int32_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955* ClientSslConfiguration_get_ServerCertificateValidationCallback_m11686C03B4F14924960670C7F08F9411C4AA3439 (ClientSslConfiguration_t212ECC383B70D9C462DC423E9D3CD27C9E74A603* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ClientSslConfiguration_defaultValidateServerCertificate_m3E2BB84D36A14CB3FA16562DD2A550D222C66AF7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955* V_1 = NULL;
	{
		RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955* L_0 = __this->____serverCertValidationCallback;
		V_0 = (bool)((((RuntimeObject*)(RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0020;
		}
	}
	{
		RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955* L_2 = (RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955*)il2cpp_codegen_object_new(RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955_il2cpp_TypeInfo_var);
		RemoteCertificateValidationCallback__ctor_mC5C0650D4E5D29475BDBDA5B43FEA44DB0DBF367(L_2, NULL, (intptr_t)((void*)ClientSslConfiguration_defaultValidateServerCertificate_m3E2BB84D36A14CB3FA16562DD2A550D222C66AF7_RuntimeMethod_var), NULL);
		__this->____serverCertValidationCallback = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____serverCertValidationCallback), (void*)L_2);
	}

IL_0020:
	{
		RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955* L_3 = __this->____serverCertValidationCallback;
		V_1 = L_3;
		goto IL_0029;
	}

IL_0029:
	{
		RemoteCertificateValidationCallback_t2F4C5801F96B2C2BF934511796C5BFEAEBF01955* L_4 = V_1;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ClientSslConfiguration_get_TargetHost_m725306CA0E2ADB08141BC48EE9BE20D628CCBA23 (ClientSslConfiguration_t212ECC383B70D9C462DC423E9D3CD27C9E74A603* __this, const RuntimeMethod* method) 
{
	String_t* V_0 = NULL;
	{
		String_t* L_0 = __this->____targetHost;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		String_t* L_1 = V_0;
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR X509Certificate_t966CC553AF25AE7991F5B4C2AACBCF6C66C8F9C4* ClientSslConfiguration_defaultSelectClientCertificate_mA37A39560426481E9ADA0F9DDC7617E58E9732D5 (RuntimeObject* ___0_sender, String_t* ___1_targetHost, X509CertificateCollection_t2900D71D188EDCA7DEB5077D36103EE5DA6805CE* ___2_clientCertificates, X509Certificate_t966CC553AF25AE7991F5B4C2AACBCF6C66C8F9C4* ___3_serverCertificate, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___4_acceptableIssuers, const RuntimeMethod* method) 
{
	X509Certificate_t966CC553AF25AE7991F5B4C2AACBCF6C66C8F9C4* V_0 = NULL;
	{
		V_0 = (X509Certificate_t966CC553AF25AE7991F5B4C2AACBCF6C66C8F9C4*)NULL;
		goto IL_0005;
	}

IL_0005:
	{
		X509Certificate_t966CC553AF25AE7991F5B4C2AACBCF6C66C8F9C4* L_0 = V_0;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ClientSslConfiguration_defaultValidateServerCertificate_m3E2BB84D36A14CB3FA16562DD2A550D222C66AF7 (RuntimeObject* ___0_sender, X509Certificate_t966CC553AF25AE7991F5B4C2AACBCF6C66C8F9C4* ___1_certificate, X509Chain_t2E7F88A4C97CAB82AF938F13A11354A0475469E5* ___2_chain, int32_t ___3_sslPolicyErrors, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		V_0 = (bool)1;
		goto IL_0005;
	}

IL_0005:
	{
		bool L_0 = V_0;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____stringLength;
		return L_0;
	}
}
