#include "function/builtin/initialize_types.hpp"
#include "ast/container/class.hpp"
#include "type/builtin_types.hpp"

namespace fsc::builtin
{
    auto initializeNumericTypes() -> void
    {
        FscBool::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);

        FscInt32::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);
        FscInt64::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);

        FscUInt32::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);
        FscUInt64::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);

        FscFloat32::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);
        FscFloat64::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);
    }

    auto initializeString() -> void
    {
        FscChar::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);
        FscString::initialize({.isTriviallyCopyable = false}, CreationType::DEFAULT);
    }

    auto initializeTemplates() -> void
    {
        VectorType::initialize({.templatesParametersCount = 1}, CreationType::DEFAULT);
        FscTemplate1::initialize({}, CreationType::TEMPLATE_HIDE_NAME);
    }

    auto initializeTypes() -> void
    {
        VoidType::initialize({.isTriviallyCopyable = true}, CreationType::DEFAULT);
        AutoType::initialize({.isTriviallyCopyable = false}, CreationType::DEFAULT);

        initializeNumericTypes();
        initializeTemplates();
        initializeString();

        TypeManager::addFscClass(ccl::makeShared<ast::Class>(
            VectorTemplate, "Vector", ccl::InitializerList<FscType>{Template1}));
    }
}// namespace fsc::builtin
