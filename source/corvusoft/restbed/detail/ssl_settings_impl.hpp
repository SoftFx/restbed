/*
 * Copyright 2013-2017, Corvusoft Ltd, All Rights Reserved.
 */

#pragma once

//System Includes
#include <string>
#include <memory>
#include <cstdint>
#include <set>

//Project Includes

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace restbed
{
    //Forward Declarations
    
    namespace detail
    {
        //Forward Declarations
        
        struct SSLSettingsImpl
        {
            uint16_t m_port = 443;
            
            bool m_http_disabled = false;
            
            bool m_sslv2_enabled = true;
            
            bool m_sslv3_enabled = true;
            
            bool m_tlsv1_enabled = true;
            
            bool m_tlsv11_enabled = true;
            
            bool m_tlsv12_enabled = true;
            
            bool m_compression_enabled = true;
            
            bool m_default_workarounds_enabled = true;
            
            bool m_single_diffie_hellman_use_enabled = true;
            
            bool m_verify_peer_enabled = false;
            
            bool m_verify_client_once_enabled = false;
            
            bool m_verify_fail_if_no_peer_cert_enabled = false;
            
            std::string m_bind_address = "";
            
            std::string m_passphrase = "";
            
            std::string m_private_key = "";
            
            std::string m_private_rsa_key = "";
            
            std::string m_certificate = "";
            
            std::string m_certificate_chain = "";
            
			std::set<std::string> m_certificate_authority_pools = {};

			std::set<std::string> m_trusted_certificate_files = {};
            
            std::string m_temporary_diffie_hellman = "";
            
            std::string m_session_id_context = "";
        };
    }
}
