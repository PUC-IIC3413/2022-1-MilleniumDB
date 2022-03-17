# Data model
Our data model is similar to the known *labeled property graph* model. In simplified terms we could say that edges were extended such that the source or destination may be another edge. To be more precise, below is the full specification.

Everything in the graph model is an **Object**, and there are 4 different types of objects:

1. **Literals**: they are the classic basic types:
    - **Integer**
    - **String**
    - **Float**
    - **Boolean**

2. **Nodes**:
    they are objects that can have the following attributes:
    - `ID`.
    - `labels`: a (possibly empty) set of **Labels**.
    - `properties`: a (possibly empty) set of pairs **<Key, Value>**. Where **Key** is a **string** and **Value** is a **literal**. A node cannot have 2 properties with the same key.

    We have 2 types of nodes depending on the ID:

    - **NamedNodes**: they have a **Name** as identifier when you add them into the database. Where **Name** is a **string**.

    - **AnonymousNodes**: they don't have a name as identifier when you add them into the database. They will have an auto-generated identifier to direcly refeer to them later.

3. **Edges**: an edge is an object that relates other objects, having the following attributes:
    - `ID` (always auto-generated in edges).
    - `from`: an **Object** (including other edge object but not itself).
    - `to`: an **Object** (including other edge object but not itself).
    - `types`: a **NamedNode**.
    - `properties`: a (possibly empty) set of pairs **<Key, Value>**. Where **Key** is a **string** and **Value** is a **literal**. An edge cannot have 2 properties with the same key.

# String domain
When we talk about a **Literal** string we support any UTF-8 string, but when we are dealing with a **Key**, a **Label** or a **Name** the strings you can use are defined by the regular expression:
- `[A-Za-z][A-Za-z0-9_]*`
