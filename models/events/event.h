#ifndef MODELS_EVENTS_EVENT_H
#define MODELS_EVENTS_EVENT_H

#include <string>

// Http status codes.
enum class StatusCode {
    // 1xx: Informational
    Continue = 100,
    SwitchingProtocols,
    Processing,

    // 2xx: Success
    Ok = 200,
    Created,
    Accepted,
    NonAuthoritativeInformation,
    NoContent,
    ResetContent,
    PartialContent,
    MultiStatus,
    AlreadyReported,
    IMUsed = 226,

    // 3xx: Redirection
    MultipleChoices = 300,
    MovedPermanently,
    Found,
    SeeOther,
    NotModified,
    UseProxy,
    // 306: not used, was proposed as "Switch Proxy" but never standardized
    TemporaryRedirect = 307,
    PermanentRedirect,

    // 4xx: Client Error
    BadRequest = 400,
    Unauthorized,
    PaymentRequired,
    Forbidden,
    NotFound,
    MethodNotAllowed,
    NotAcceptable,
    ProxyAuthenticationRequired,
    RequestTimeout,
    Conflict,
    Gone,
    LengthRequired,
    PreconditionFailed,
    PayloadTooLarge,
    UriTooLong,
    UnsupportedMediaType,
    RequestRangeNotSatisfiable,
    ExpectationFailed,
    ImATeapot,
    MisdirectedRequest = 421,
    UnprocessableEntity,
    Locked,
    FailedDependency,
    UpgradeRequired = 426,
    PreconditionRequired = 428,
    TooManyRequests,
    RequestHeaderFieldsTooLarge = 431,
    UnavailableForLegalReasons = 451,

    // 5xx: Server Error
    InternalServerError = 500,
    NotImplemented,
    BadGateway,
    ServiceUnavailable,
    GatewayTimeout,
    HttpVersionNotSupported,
    VariantAlsoNegotiates,
    InsufficientStorage,
    LoopDetected,
    NotExtended = 510,
    NetworkAuthenticationRequired,
    NetworkConnectTimeoutError = 599,
};

class Event {
public:
    virtual ~Event() = default;

    virtual void set_status(const StatusCode& status) = 0;

    virtual StatusCode status() const = 0;

    virtual void set_message(const std::string& str) = 0;

    virtual std::string message() const = 0;
};

#endif  // MODELS_EVENT_EVENT_H