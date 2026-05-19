# LeetCode Practice

This repo is organized for quick lookup by problem topic, with each solution stored as:

```text
problems/<topic>/<leetcode_slug>.<language>
```

Use lowercase `snake_case` slugs that match the LeetCode title closely enough to search by memory. For example, `problems/arrays_hashing/product_of_array_except_self.c`.

## Layout

```text
notes/          Review notes, patterns, mistakes, and revisit logs
problems/       Solutions grouped by primary topic
scripts/        Small repo helpers
templates/      Reusable snippets and pattern templates
```

## Adding A Problem

Create a new solution from the standard header template:

```sh
./scripts/new arrays_hashing contains_duplicate c
```

You can also pass a full path:

```sh
./scripts/new problems/trees/maximum_depth_binary_tree.c
```

## Finding Things

- Browse the topic folders in [problems](problems/README.md).
- Search by title words: `rg "Product of Array Except Self" problems`.
- Search by pattern or lesson: `rg "prefix" notes problems`.
