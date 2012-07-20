/**
 * @file RocketListener.cpp
 * @date 2012-06-09
 * @author fritz@fritzmahnke.com
 *
 */
#ifdef USE_LIBROCKET
#include "RocketListener.h"
#include "Rocket/Core.h"
#include "Scroll.h"
#include "WidgetManager.h"

using Rocket::Core::Element;

void RocketListener::ProcessEvent (Rocket::Core::Event &event)
{
    Element *element = event.GetTargetElement ();
    const orxSTRING tag = element->GetTagName ().CString ();

    // Data grid cell?
    if (orxString_Compare (tag, "datagridcell") == 0)
    {
	Rocket::Core::String innerRML;
	element->GetInnerRML (innerRML);
	const orxSTRING rml = innerRML.CString ();

	Element *parent = element->GetParentNode ();
	while (parent != orxNULL)
	{
	    const orxSTRING parentTag = parent->GetTagName ().CString ();
	    // Tag is the parent DataGrid element?
	    if (orxString_Compare (parentTag, "datagrid") == 0)
	    {
		const orxSTRING dataGridId = parent->GetId ().CString ();
		m_widgetManager->SetSelectedItem (dataGridId, rml);
		m_widgetManager->OnMouseClick (dataGridId);
	    }
	    parent = parent->GetParentNode ();
	}
    }
}
#endif