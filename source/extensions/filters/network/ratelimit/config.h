#pragma once

#include "envoy/extensions/filters/network/ratelimit/v3alpha/rate_limit.pb.h"
#include "envoy/extensions/filters/network/ratelimit/v3alpha/rate_limit.pb.validate.h"

#include "extensions/filters/common/ratelimit/ratelimit.h"
#include "extensions/filters/network/common/factory_base.h"
#include "extensions/filters/network/well_known_names.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace RateLimitFilter {

/**
 * Config registration for the rate limit filter. @see NamedNetworkFilterConfigFactory.
 */
class RateLimitConfigFactory
    : public Common::FactoryBase<
          envoy::extensions::filters::network::ratelimit::v3alpha::RateLimit> {
public:
  RateLimitConfigFactory() : FactoryBase(NetworkFilterNames::get().RateLimit) {}

private:
  Network::FilterFactoryCb createFilterFactoryFromProtoTyped(
      const envoy::extensions::filters::network::ratelimit::v3alpha::RateLimit& proto_config,
      Server::Configuration::FactoryContext& context) override;
};

} // namespace RateLimitFilter
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
