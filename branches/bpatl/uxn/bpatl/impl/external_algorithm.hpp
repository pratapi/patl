#ifndef BPATL_IMPL_EXTERNAL_ALGORITHM_HPP
#define BPATL_IMPL_EXTERNAL_ALGORITHM_HPP

#include "../../patl/impl/algorithm.hpp"

namespace uxn
{
namespace bpatl
{
namespace impl
{

/// external memory algorithm template
template <typename T, typename This, typename ContainerProvider>
class external_algorithm_generic
    : public patl::impl::algorithm_generic<T, This, ContainerProvider>
{
    typedef patl::impl::algorithm_generic<T, This, ContainerProvider> super;
    typedef ContainerProvider cont_prov_t;
    typedef typename cont_prov_t::cont_type cont_type;
    typedef typename cont_type::node_block node_block;

public:
    /// zero-init default ctor
    explicit external_algorithm_generic(const cont_prov_t *cont_prov = 0)
        : super(cont_prov)
    {
    }

    /// simple init ctor
    external_algorithm_generic(const cont_prov_t *cont_prov, const node_type *q, word_t qid)
        : super(cont_prov, q, qid)
    {
    }

    /// compact init ctor
    external_algorithm_generic(const cont_prov_t *cont_prov, word_t qq)
        : super(cont_prov, qq)
    {
    }

    const node_type *get_parent(const node_type *nod) const
    {
        return nod->get_parent(this->cont());
    }
    node_type *get_parent(node_type *nod) const
    {
        return nod->get_parent(this->cont());
    }

    const node_type *get_xlink(const node_type *nod, word_t id) const
    {
        return nod->get_xlink(this->cont(), id);
    }
    node_type *get_xlink(node_type *nod, word_t id) const
    {
        return nod->get_xlink(this->cont(), id);
    }

    void set_parentid(node_type *nod, node_type *parent, word_t id) const
    {
        return nod->set_parentid(this->cont(), parent, id);
    }

    void set_xlinktag(node_type *nod, word_t id, const node_type *link, word_t tag) const
    {
        return nod->set_xlinktag(this->cont(), id, link, tag);
    }
};

} // namespace impl
} // namespace bpatl
} // namespace uxn

#endif