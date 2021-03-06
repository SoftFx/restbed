/*
 * Copyright 2013-2017, Corvusoft Ltd, All Rights Reserved.
 */

//System Includes

//Project Includes
#include "corvusoft/restbed/uri.hpp"
#include "corvusoft/restbed/string.hpp"
#include "corvusoft/restbed/ssl_settings.hpp"
#include "corvusoft/restbed/detail/ssl_settings_impl.hpp"

//External Includes

//System Namespaces
using std::string;
using std::unique_ptr;
using std::set;

//Project Namespaces
using restbed::detail::SSLSettingsImpl;

//External Namespaces

namespace restbed
{
    SSLSettings::SSLSettings( void ) : m_pimpl( new SSLSettingsImpl )
    {
        return;
    }
    
    SSLSettings::~SSLSettings( void )
    {
        return;
    }
    
    bool SSLSettings::has_disabled_http( void ) const
    {
        return m_pimpl->m_http_disabled;
    }
    
    bool SSLSettings::has_enabled_sslv2( void ) const
    {
        return m_pimpl->m_sslv2_enabled;
    }
    
    bool SSLSettings::has_enabled_sslv3( void ) const
    {
        return m_pimpl->m_sslv3_enabled;
    }
    
    bool SSLSettings::has_enabled_tlsv1( void ) const
    {
        return m_pimpl->m_tlsv1_enabled;
    }
    
    bool SSLSettings::has_enabled_tlsv11( void ) const
    {
        return m_pimpl->m_tlsv11_enabled;
    }
    
    bool SSLSettings::has_enabled_tlsv12( void ) const
    {
        return m_pimpl->m_tlsv12_enabled;
    }
    
    bool SSLSettings::has_enabled_compression( void ) const
    {
        return m_pimpl->m_compression_enabled;
    }
    
    bool SSLSettings::has_enabled_default_workarounds( void ) const
    {
        return m_pimpl->m_default_workarounds_enabled;
    }
    
    bool SSLSettings::has_enabled_single_diffie_hellman_use( void ) const
    {
        return m_pimpl->m_single_diffie_hellman_use_enabled;
    }
    
    bool SSLSettings::has_enabled_verify_peer( void ) const
    {
        return m_pimpl->m_verify_peer_enabled;
    }
    
    bool SSLSettings::has_enabled_verify_client_once( void ) const
    {
        return m_pimpl->m_verify_client_once_enabled;
    }
    
    bool SSLSettings::has_enabled_verify_fail_if_no_peer_cert( void ) const
    {
        return m_pimpl->m_verify_fail_if_no_peer_cert_enabled;
    }
    
    uint16_t SSLSettings::get_port( void ) const
    {
        return m_pimpl->m_port;
    }
    
    string SSLSettings::get_bind_address( void ) const
    {
        return m_pimpl->m_bind_address;
    }
    
    string SSLSettings::get_certificate( void ) const
    {
        return m_pimpl->m_certificate;
    }
    
    string SSLSettings::get_passphrase( void ) const
    {
        return m_pimpl->m_passphrase;
    }
    
    string SSLSettings::get_private_key( void ) const
    {
        return m_pimpl->m_private_key;
    }
    
    string SSLSettings::get_private_rsa_key( void ) const
    {
        return m_pimpl->m_private_rsa_key;
    }
    
    string SSLSettings::get_certificate_chain( void ) const
    {
        return m_pimpl->m_certificate_chain;
    }
    
    string SSLSettings::get_temporary_diffie_hellman( void ) const
    {
        return m_pimpl->m_temporary_diffie_hellman;
    }
    
    set<string> SSLSettings::get_certificate_authority_pools( void ) const
    {
        return m_pimpl->m_certificate_authority_pools;
    }

	set<string> SSLSettings::get_trusted_certififcate_files(void) const
	{
		return m_pimpl->m_trusted_certificate_files;
	}
    
    string SSLSettings::get_session_id(void) const
    {
        return m_pimpl->m_session_id_context;
    }
    
    void SSLSettings::set_port( const uint16_t value )
    {
        m_pimpl->m_port = value;
    }
    
    void SSLSettings::set_bind_address( const string& value )
    {
        m_pimpl->m_bind_address = value;
    }
    
    void SSLSettings::set_http_disabled( const bool value )
    {
        m_pimpl->m_http_disabled = value;
    }
    
    void SSLSettings::set_sslv2_enabled( const bool value )
    {
        m_pimpl->m_sslv2_enabled = value;
    }
    
    void SSLSettings::set_sslv3_enabled( const bool value )
    {
        m_pimpl->m_sslv3_enabled = value;
    }
    
    void SSLSettings::set_tlsv1_enabled( const bool value )
    {
        m_pimpl->m_tlsv1_enabled = value;
    }
    
    void SSLSettings::set_tlsv11_enabled( const bool value )
    {
        m_pimpl->m_tlsv11_enabled = value;
    }
    
    void SSLSettings::set_tlsv12_enabled( const bool value )
    {
        m_pimpl->m_tlsv12_enabled = value;
    }
    
    void SSLSettings::set_compression_enabled( const bool value )
    {
        m_pimpl->m_compression_enabled = value;
    }
    
    void SSLSettings::set_default_workarounds_enabled( const bool value )
    {
        m_pimpl->m_default_workarounds_enabled = value;
    }
    
    void SSLSettings::set_single_diffie_hellman_use_enabled( const bool value )
    {
        m_pimpl->m_single_diffie_hellman_use_enabled = value;
    }
    
    void SSLSettings::set_certificate( const Uri& value )
    {
        m_pimpl->m_certificate = String::remove( "file://", value.to_string( ), String::CASE_INSENSITIVE );
    }
    
    void SSLSettings::set_certificate_chain( const Uri& value )
    {
        m_pimpl->m_certificate_chain = String::remove( "file://", value.to_string( ), String::CASE_INSENSITIVE );
    }
    
    void SSLSettings::add_certificate_authority_pool( const Uri& value )
    {
        m_pimpl->m_certificate_authority_pools.insert(String::remove("file://", value.to_string(), String::CASE_INSENSITIVE));
    }
    
	void SSLSettings::remove_certificate_authority_pool(const Uri& value)
	{
		m_pimpl->m_certificate_authority_pools.erase(String::remove("file://", value.to_string(), String::CASE_INSENSITIVE));
	}

	void SSLSettings::add_trusted_certificate_file(const Uri& value)
	{
		m_pimpl->m_trusted_certificate_files.insert(String::remove("file://", value.to_string(), String::CASE_INSENSITIVE));
	}

	void SSLSettings::remove_trusted_certificate_file(const Uri& value)
	{
		m_pimpl->m_trusted_certificate_files.erase(String::remove("file://", value.to_string(), String::CASE_INSENSITIVE));
	}

	void SSLSettings::set_passphrase(const string& value)
    {
        m_pimpl->m_passphrase = value;
    }
    
    void SSLSettings::set_private_key( const Uri& value )
    {
        m_pimpl->m_private_key = String::remove( "file://", value.to_string( ), String::CASE_INSENSITIVE );
    }
    
    void SSLSettings::set_private_rsa_key( const Uri& value )
    {
        m_pimpl->m_private_rsa_key = String::remove( "file://", value.to_string( ), String::CASE_INSENSITIVE );
    }
    
    void SSLSettings::set_temporary_diffie_hellman( const Uri& value )
    {
        m_pimpl->m_temporary_diffie_hellman = String::remove( "file://", value.to_string( ), String::CASE_INSENSITIVE );
    }
    
    void SSLSettings::set_session_id(const std::string & value)
    {
        m_pimpl->m_session_id_context = value;
    }
    
    void SSLSettings::set_verify_peer_enabled(const bool value)
    {
        m_pimpl->m_verify_peer_enabled = value;
    }
    
    void SSLSettings::set_verify_client_once_enabled(const bool value)
    {
        m_pimpl->m_verify_client_once_enabled = value;
    }
    
    void SSLSettings::set_verify_fail_if_no_peer_cert_enabled(const bool value)
    {
        m_pimpl->m_verify_fail_if_no_peer_cert_enabled = value;
    }
}
