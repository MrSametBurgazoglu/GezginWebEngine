
# Css Scraper Set Property Value Functions Standard Flow
> Css Property Type 1 => This property have a struct like animation or background and have sub properties like background-color etc.  
> Css Property Type 2 => This property in a struct of top property like background-color itself  
> Css Property Type 3 => This property don't have a struct or in a struct. Its in css_widget

## Scraping values for Css Property Type 1:
```
if value is "inherit":
    css_widget->property_inherit = true
else:
    css_widget->property_inherit = false
    if css_widget->property is null:
        css_widget->property = malloc(size of property)
    if value is "initial":
        set all sub properties to their default values
    else:
        set_property()
```

## Scraping values for Css Property Type 2:

```
if value is "inherit":
    if css_widget->top_property is not inherit:
        if css_widget->top_property is null:
            css_widget->top_property = malloc(size of top_property)
        css_widget->top_property->property_inherit = true
else:
    if css_widget->top_property is null:
        css_widget->top_property = malloc(size of top_property)
    if css_widget->top_property is inherit:
        set all sub_properties to inherit except the property
    css_widget->property_inherit = false
    if property is also a top property:
      malloc property and its sub properties
    if value is "initial":
        set property to default value
    else:
        set_property()
```
